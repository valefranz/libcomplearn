#ifndef __COMPRESSOR_BASE_H
#define __COMPRESSOR_BASE_H

#include <stdint.h>

#define CL_OK 0
#define CL_ERROR 1

struct CLDatum {
  unsigned char *data;
  uint64_t length;
};

struct CLCompressorConfig clNewConfig(void);

struct CLCompressorConfig {
  unsigned char config[1024];
};

struct CLCompressor {
  char *(*name)(void);
  char *(*version)(void);
  char *(*description)(void);
  char *(*parameters)(void);
  int64_t  (*windowSize)(void);
  void (*updateConfiguration)(struct CLCompressorConfig *conf, const char *k, const char *v);
  uint64_t (*compressedSize)(struct CLDatum input, struct CLCompressorConfig *conf);
  struct CLDatum (*compressDatum)(struct CLDatum input, struct CLCompressorConfig *conf);
  struct CLDatum (*decompressDatum)(struct CLDatum input);
};

extern struct CLCompressor cl_zlib;

#endif
