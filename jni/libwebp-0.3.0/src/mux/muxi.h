// Copyright 2011 Google Inc. All Rights Reserved.
//
// This code is licensed under the same terms as WebM:
//  Software License Agreement:  http://www.webmproject.org/license/software/
//  Additional IP Rights Grant:  http://www.webmproject.org/license/additional/
// -----------------------------------------------------------------------------
//
// Internal header for mux library.
//
// Author: Urvang (urvang@google.com)

#ifndef WEBP_MUX_MUXI_H_
#define WEBP_MUX_MUXI_H_

#include <stdlib.h>
#include "../dec/vp8i.h"
#include "../dec/vp8li.h"
#include "../webp/mux.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

//------------------------------------------------------------------------------
// Defines and constants.

#define MUX_MAJ_VERSION 0
#define MUX_MIN_VERSION 1
#define MUX_REV_VERSION 0

// Chunk object.
typedef struct WebPChunk WebPChunk;
struct WebPChunk {
  uint32_t        tag_;
  int             owner_;  // True if *data_ memory is owned internally.
                           // VP8X, ANIM, and other internally created chunks
                           // like ANMF/FRGM are always owned.
  WebPData        data_;
  WebPChunk*      next_;
};

// MuxImage object. Store a full WebP image (including ANMF/FRGM chunk, ALPH
// chunk and VP8/VP8L chunk),
typedef struct WebPMuxImage WebPMuxImage;
struct WebPMuxImage {
  WebPChunk*  header_;      // Corresponds to WEBP_CHUNK_ANMF/WEBP_CHUNK_FRGM.
  WebPChunk*  alpha_;       // Corresponds to WEBP_CHUNK_ALPHA.
  WebPChunk*  img_;         // Corresponds to WEBP_CHUNK_IMAGE.
  int         is_partial_;  // True if only some of the chunks are filled.
  WebPMuxImage* next_;
};

// Main mux object. Stores data chunks.
struct WebPMux {
  WebPMuxImage*   images_;
  WebPChunk*      iccp_;
  WebPChunk*      exif_;
  WebPChunk*      xmp_;
  WebPChunk*      anim_;
  WebPChunk*      vp8x_;

  WebPChunk*  unknown_;
};

// CHUNK_INDEX enum: used for indexing within 'kChunks' (defined below) only.
// Note: the reason for having two enums ('WebPChunkId' and 'CHUNK_INDEX') is to
// allow two different chunks to have the same id (e.g. WebPChunkId
// 'WEBP_CHUNK_IMAGE' can correspond to CHUNK_INDEX 'IDX_VP8' or 'IDX_VP8L').
typedef enum {
  IDX_VP8X = 0,
  IDX_ICCP,
  IDX_ANIM,
  IDX_ANMF,
  IDX_FRGM,
  IDX_ALPHA,
  IDX_VP8,
  IDX_VP8L,
  IDX_EXIF,
  IDX_XMP,
  IDX_UNKNOWN,

  IDX_NIL,
  IDX_LAST_CHUNK
} CHUNK_INDEX;

#define NIL_TAG 0x00000000u  // To signal void chunk.

typedef struct {
  uint32_t      tag;
  WebPChunkId   id;
  uint32_t      size;
} ChunkInfo;

extern const ChunkInfo kChunks[IDX_LAST_CHUNK];

//------------------------------------------------------------------------------
// Chunk object management.

// Initialize.
void ChunkInit(WebPChunk* const chunk);

// Get chunk index from chunk tag. Returns IDX_NIL if not found.
CHUNK_INDEX ChunkGetIndexFromTag(uint32_t tag);

// Get chunk id from chunk tag. Returns WEBP_CHUNK_NIL if not found.
WebPChunkId ChunkGetIdFromTag(uint32_t tag);

// Convert a fourcc string to a tag.
uint32_t ChunkGetTagFromFourCC(const char fourcc[4]);

// Get chunk index from fourcc. Returns IDX_UNKNOWN if given fourcc is unknown.
CHUNK_INDEX ChunkGetIndexFromFourCC(const char fourcc[4]);

// Search for nth chunk with given 'tag' in the chunk list.
// nth = 0 means "last of the list".
WebPChunk* ChunkSearchList(WebPChunk* first, uint32_t nth, uint32_t tag);

// Fill the chunk with the given data.
WebPMuxError ChunkAssignData(WebPChunk* chunk, const WebPData* const data,
                             int copy_data, uint32_t tag);

// Sets 'chunk' at nth position in the 'chunk_list'.
// nth = 0 has the special meaning "last of the list".
// On success ownership is transferred from 'chunk' to the 'chunk_list'.
WebPMuxError ChunkSetNth(WebPChunk* chunk, WebPChunk** chunk_list,
                         uint32_t nth);

// Releases chunk and returns chunk->next_.
WebPChunk* ChunkRelease(WebPChunk* const chunk);

// Deletes given chunk & returns chunk->next_.
WebPChunk* ChunkDelete(WebPChunk* const chunk);

// Returns size of the chunk including chunk header and padding byte (if any).
static WEBP_INLINE size_t SizeWithPadding(size_t chunk_size) {
  return CHUNK_HEADER_SIZE + ((chunk_size + 1) & ~1U);
}

// Size of a chunk including header and padding.
static WEBP_INLINE size_t ChunkDiskSize(const WebPChunk* chunk) {
  const size_t data_size = chunk->data_.size;
  assert(data_size < MAX_CHUNK_PAYLOAD);
  return SizeWithPadding(data_size);
}

// Write out the given list of chunks into 'dst'.
uint8_t* ChunkListEmit(const WebPChunk* chunk_list, uint8_t* dst);

// Get the width, height and has_alpha info of image stored in 'image_chunk'.
WebPMuxError MuxGetImageInfo(const WebPChunk* const image_chunk,
                             int* const width, int* const height,
                             int* const has_alpha);

//------------------------------------------------------------------------------
// MuxImage object management.

// Initialize.
void MuxImageInit(WebPMuxImage* const wpi);

// Releases image 'wpi' and returns wpi->next.
WebPMuxImage* MuxImageRelease(WebPMuxImage* const wpi);

// Delete image 'wpi' and return the next image in the list or NULL.
// 'wpi' can be NULL.
WebPMuxImage* MuxImageDelete(WebPMuxImage* const wpi);

// Count number of images matching the given tag id in the 'wpi_list'.
// If id == WEBP_CHUNK_NIL, all images will be matched.
int MuxImageCount(const WebPMuxImage* wpi_list, WebPChunkId id);

// Check if given ID corresponds to an image related chunk.
static WEBP_INLINE int IsWPI(WebPChunkId id) {
  switch (id) {
    case WEBP_CHUNK_ANMF:
    case WEBP_CHUNK_FRGM:
    case WEBP_CHUNK_ALPHA:
    case WEBP_CHUNK_IMAGE:  return 1;
    default:        return 0;
  }
}

// Pushes 'wpi' at the end of 'wpi_list'.
WebPMuxError MuxImagePush(const WebPMuxImage* wpi, WebPMuxImage** wpi_list);

// Delete nth image in the image list.
WebPMuxError MuxImageDeleteNth(WebPMuxImage** wpi_list, uint32_t nth);

// Get nth image in the image list.
WebPMuxError MuxImageGetNth(const WebPMuxImage** wpi_list, uint32_t nth,
                            WebPMuxImage** wpi);

// Total size of the given image.
size_t MuxImageDiskSize(const WebPMuxImage* const wpi);

// Write out the given image into 'dst'.
uint8_t* MuxImageEmit(const WebPMuxImage* const wpi, uint8_t* dst);

//------------------------------------------------------------------------------
// Helper methods for mux.

// Checks if the given image list contains at least one lossless image.
int MuxHasLosslessImages(const WebPMuxImage* images);

// Write out RIFF header into 'data', given total data size 'size'.
uint8_t* MuxEmitRiffHeader(uint8_t* const data, size_t size);

// Returns the list where chunk with given ID is to be inserted in mux.
// Return value is NULL if this chunk should be inserted in mux->images_ list
// or if 'id' is not known.
WebPChunk** MuxGetChunkListFromId(const WebPMux* mux, WebPChunkId id);

// Validates the given mux object.
WebPMuxError MuxValidate(const WebPMux* const mux);

//------------------------------------------------------------------------------

#if defined(__cplusplus) || defined(c_plusplus)
}    // extern "C"
#endif

#endif  /* WEBP_MUX_MUXI_H_ */
