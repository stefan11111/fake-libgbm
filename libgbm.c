#ifndef _GBM_H_
#define _GBM_H_
#define __GBM__ 1
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
"C" {
#endif
struct gbm_device;
struct gbm_bo;
struct gbm_surface;
union gbm_bo_handle {
void *ptr;
int32_t s32;
uint32_t u32;
int64_t s64;
uint64_t u64;
};
enum gbm_bo_format {
GBM_BO_FORMAT_XRGB8888, 
GBM_BO_FORMAT_ARGB8888
};
#define __gbm_fourcc_code(a,b,c,d) ((uint32_t)(a) | ((uint32_t)(b) << 8) | \
((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))
#define GBM_FORMAT_BIG_ENDIAN (1<<31) 
#define GBM_FORMAT_C8		__gbm_fourcc_code('C', '8', ' ', ' ') 
#define GBM_FORMAT_R8		__gbm_fourcc_code('R', '8', ' ', ' ') 
#define GBM_FORMAT_R16          __gbm_fourcc_code('R', '1', '6', ' ') 
#define GBM_FORMAT_GR88		__gbm_fourcc_code('G', 'R', '8', '8') 
#define GBM_FORMAT_RG1616	__gbm_fourcc_code('R', 'G', '3', '2') 
#define GBM_FORMAT_GR1616	__gbm_fourcc_code('G', 'R', '3', '2') 
#define GBM_FORMAT_RGB332	__gbm_fourcc_code('R', 'G', 'B', '8') 
#define GBM_FORMAT_BGR233	__gbm_fourcc_code('B', 'G', 'R', '8') 
#define GBM_FORMAT_XRGB4444	__gbm_fourcc_code('X', 'R', '1', '2') 
#define GBM_FORMAT_XBGR4444	__gbm_fourcc_code('X', 'B', '1', '2') 
#define GBM_FORMAT_RGBX4444	__gbm_fourcc_code('R', 'X', '1', '2') 
#define GBM_FORMAT_BGRX4444	__gbm_fourcc_code('B', 'X', '1', '2') 
#define GBM_FORMAT_ARGB4444	__gbm_fourcc_code('A', 'R', '1', '2') 
#define GBM_FORMAT_ABGR4444	__gbm_fourcc_code('A', 'B', '1', '2') 
#define GBM_FORMAT_RGBA4444	__gbm_fourcc_code('R', 'A', '1', '2') 
#define GBM_FORMAT_BGRA4444	__gbm_fourcc_code('B', 'A', '1', '2') 
#define GBM_FORMAT_XRGB1555	__gbm_fourcc_code('X', 'R', '1', '5') 
#define GBM_FORMAT_XBGR1555	__gbm_fourcc_code('X', 'B', '1', '5') 
#define GBM_FORMAT_RGBX5551	__gbm_fourcc_code('R', 'X', '1', '5') 
#define GBM_FORMAT_BGRX5551	__gbm_fourcc_code('B', 'X', '1', '5') 
#define GBM_FORMAT_ARGB1555	__gbm_fourcc_code('A', 'R', '1', '5') 
#define GBM_FORMAT_ABGR1555	__gbm_fourcc_code('A', 'B', '1', '5') 
#define GBM_FORMAT_RGBA5551	__gbm_fourcc_code('R', 'A', '1', '5') 
#define GBM_FORMAT_BGRA5551	__gbm_fourcc_code('B', 'A', '1', '5') 
#define GBM_FORMAT_RGB565	__gbm_fourcc_code('R', 'G', '1', '6') 
#define GBM_FORMAT_BGR565	__gbm_fourcc_code('B', 'G', '1', '6') 
#define GBM_FORMAT_RGB888	__gbm_fourcc_code('R', 'G', '2', '4') 
#define GBM_FORMAT_BGR888	__gbm_fourcc_code('B', 'G', '2', '4') 
#define GBM_FORMAT_XRGB8888	__gbm_fourcc_code('X', 'R', '2', '4') 
#define GBM_FORMAT_XBGR8888	__gbm_fourcc_code('X', 'B', '2', '4') 
#define GBM_FORMAT_RGBX8888	__gbm_fourcc_code('R', 'X', '2', '4') 
#define GBM_FORMAT_BGRX8888	__gbm_fourcc_code('B', 'X', '2', '4') 
#define GBM_FORMAT_ARGB8888	__gbm_fourcc_code('A', 'R', '2', '4') 
#define GBM_FORMAT_ABGR8888	__gbm_fourcc_code('A', 'B', '2', '4') 
#define GBM_FORMAT_RGBA8888	__gbm_fourcc_code('R', 'A', '2', '4') 
#define GBM_FORMAT_BGRA8888	__gbm_fourcc_code('B', 'A', '2', '4') 
#define GBM_FORMAT_XRGB2101010	__gbm_fourcc_code('X', 'R', '3', '0') 
#define GBM_FORMAT_XBGR2101010	__gbm_fourcc_code('X', 'B', '3', '0') 
#define GBM_FORMAT_RGBX1010102	__gbm_fourcc_code('R', 'X', '3', '0') 
#define GBM_FORMAT_BGRX1010102	__gbm_fourcc_code('B', 'X', '3', '0') 
#define GBM_FORMAT_ARGB2101010	__gbm_fourcc_code('A', 'R', '3', '0') 
#define GBM_FORMAT_ABGR2101010	__gbm_fourcc_code('A', 'B', '3', '0') 
#define GBM_FORMAT_RGBA1010102	__gbm_fourcc_code('R', 'A', '3', '0') 
#define GBM_FORMAT_BGRA1010102	__gbm_fourcc_code('B', 'A', '3', '0') 
#define GBM_FORMAT_XBGR16161616	__gbm_fourcc_code('X', 'B', '4', '8') 
#define GBM_FORMAT_ABGR16161616	__gbm_fourcc_code('A', 'B', '4', '8') 
#define GBM_FORMAT_XBGR16161616F __gbm_fourcc_code('X', 'B', '4', 'H') 
#define GBM_FORMAT_ABGR16161616F __gbm_fourcc_code('A', 'B', '4', 'H') 
#define GBM_FORMAT_YUYV		__gbm_fourcc_code('Y', 'U', 'Y', 'V') 
#define GBM_FORMAT_YVYU		__gbm_fourcc_code('Y', 'V', 'Y', 'U') 
#define GBM_FORMAT_UYVY		__gbm_fourcc_code('U', 'Y', 'V', 'Y') 
#define GBM_FORMAT_VYUY		__gbm_fourcc_code('V', 'Y', 'U', 'Y') 
#define GBM_FORMAT_AYUV		__gbm_fourcc_code('A', 'Y', 'U', 'V') 
#define GBM_FORMAT_NV12		__gbm_fourcc_code('N', 'V', '1', '2') 
#define GBM_FORMAT_NV21		__gbm_fourcc_code('N', 'V', '2', '1') 
#define GBM_FORMAT_NV16		__gbm_fourcc_code('N', 'V', '1', '6') 
#define GBM_FORMAT_NV61		__gbm_fourcc_code('N', 'V', '6', '1') 
#define GBM_FORMAT_YUV410	__gbm_fourcc_code('Y', 'U', 'V', '9') 
#define GBM_FORMAT_YVU410	__gbm_fourcc_code('Y', 'V', 'U', '9') 
#define GBM_FORMAT_YUV411	__gbm_fourcc_code('Y', 'U', '1', '1') 
#define GBM_FORMAT_YVU411	__gbm_fourcc_code('Y', 'V', '1', '1') 
#define GBM_FORMAT_YUV420	__gbm_fourcc_code('Y', 'U', '1', '2') 
#define GBM_FORMAT_YVU420	__gbm_fourcc_code('Y', 'V', '1', '2') 
#define GBM_FORMAT_YUV422	__gbm_fourcc_code('Y', 'U', '1', '6') 
#define GBM_FORMAT_YVU422	__gbm_fourcc_code('Y', 'V', '1', '6') 
#define GBM_FORMAT_YUV444	__gbm_fourcc_code('Y', 'U', '2', '4') 
#define GBM_FORMAT_YVU444	__gbm_fourcc_code('Y', 'V', '2', '4') 
struct gbm_format_name_desc {
char name[5];
};
enum gbm_bo_flags {
GBM_BO_USE_SCANOUT = (1 << 0),
GBM_BO_USE_CURSOR = (1 << 1),
GBM_BO_USE_CURSOR_64X64 = GBM_BO_USE_CURSOR,
GBM_BO_USE_RENDERING = (1 << 2),
GBM_BO_USE_WRITE = (1 << 3),
GBM_BO_USE_LINEAR = (1 << 4),
GBM_BO_USE_PROTECTED = (1 << 5),
GBM_BO_USE_FRONT_RENDERING = (1 << 6),
GBM_BO_FIXED_COMPRESSION_DEFAULT = (1 << 7),
GBM_BO_FIXED_COMPRESSION_1BPC = (2 << 7),
GBM_BO_FIXED_COMPRESSION_2BPC = (3 << 7),
GBM_BO_FIXED_COMPRESSION_3BPC = (4 << 7),
GBM_BO_FIXED_COMPRESSION_4BPC = (5 << 7),
GBM_BO_FIXED_COMPRESSION_5BPC = (6 << 7),
GBM_BO_FIXED_COMPRESSION_6BPC = (7 << 7),
GBM_BO_FIXED_COMPRESSION_7BPC = (8 << 7),
GBM_BO_FIXED_COMPRESSION_8BPC = (9 << 7),
GBM_BO_FIXED_COMPRESSION_9BPC = (10 << 7),
GBM_BO_FIXED_COMPRESSION_10BPC = (11 << 7),
GBM_BO_FIXED_COMPRESSION_11BPC = (12 << 7),
GBM_BO_FIXED_COMPRESSION_12BPC = (13 << 7),
};
#define GBM_BO_FIXED_COMPRESSION_MASK (((1 << 11) - 1) & ~((1 << 7) - 1))
int
gbm_device_get_fd(struct gbm_device *gbm) { return 0; }
const char *
gbm_device_get_backend_name(struct gbm_device *gbm) { return 0; }
int
gbm_device_is_format_supported(struct gbm_device *gbm,
uint32_t format, uint32_t flags) { return 0; }
int
gbm_device_get_format_modifier_plane_count(struct gbm_device *gbm,
uint32_t format,
uint64_t modifier) { return 0; }
void
gbm_device_destroy(struct gbm_device *gbm) {}
struct gbm_device *
gbm_create_device(int fd) { return 0; }
struct gbm_bo *
gbm_bo_create(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format, uint32_t flags) { return 0; }
struct gbm_bo *
gbm_bo_create_with_modifiers(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format,
const uint64_t *modifiers,
const unsigned int count) { return 0; }
struct gbm_bo *
gbm_bo_create_with_modifiers2(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format,
const uint64_t *modifiers,
const unsigned int count,
uint32_t flags) { return 0; }
#define GBM_BO_IMPORT_WL_BUFFER         0x5501
#define GBM_BO_IMPORT_EGL_IMAGE         0x5502
#define GBM_BO_IMPORT_FD                0x5503
#define GBM_BO_IMPORT_FD_MODIFIER       0x5504
struct gbm_import_fd_data {
int fd;
uint32_t width;
uint32_t height;
uint32_t stride;
uint32_t format;
};
#define GBM_MAX_PLANES 4
struct gbm_import_fd_modifier_data {
uint32_t width;
uint32_t height;
uint32_t format;
uint32_t num_fds;
int fds[GBM_MAX_PLANES];
int strides[GBM_MAX_PLANES];
int offsets[GBM_MAX_PLANES];
uint64_t modifier;
};
struct gbm_bo *
gbm_bo_import(struct gbm_device *gbm, uint32_t type,
void *buffer, uint32_t flags) { return 0; }
enum gbm_bo_transfer_flags {
GBM_BO_TRANSFER_READ = (1 << 0),
GBM_BO_TRANSFER_WRITE = (1 << 1),
GBM_BO_TRANSFER_READ_WRITE = (GBM_BO_TRANSFER_READ | GBM_BO_TRANSFER_WRITE),
};
void *
gbm_bo_map(struct gbm_bo *bo,
uint32_t x, uint32_t y, uint32_t width, uint32_t height,
uint32_t flags, uint32_t *stride, void **map_data) { return 0; }
void
gbm_bo_unmap(struct gbm_bo *bo, void *map_data) {}
uint32_t
gbm_bo_get_width(struct gbm_bo *bo) { return 0; }
uint32_t
gbm_bo_get_height(struct gbm_bo *bo) { return 0; }
uint32_t
gbm_bo_get_stride(struct gbm_bo *bo) { return 0; }
uint32_t
gbm_bo_get_stride_for_plane(struct gbm_bo *bo, int plane) { return 0; }
uint32_t
gbm_bo_get_format(struct gbm_bo *bo) { return 0; }
uint32_t
gbm_bo_get_bpp(struct gbm_bo *bo) { return 0; }
uint32_t
gbm_bo_get_offset(struct gbm_bo *bo, int plane) { return 0; }
struct gbm_device *
gbm_bo_get_device(struct gbm_bo *bo) { return 0; }
union gbm_bo_handle
gbm_bo_get_handle(struct gbm_bo *bo) { return (union gbm_bo_handle){0}; }
int
gbm_bo_get_fd(struct gbm_bo *bo) { return 0; }
uint64_t
gbm_bo_get_modifier(struct gbm_bo *bo) { return 0; }
int
gbm_bo_get_plane_count(struct gbm_bo *bo) { return 0; }
union gbm_bo_handle
gbm_bo_get_handle_for_plane(struct gbm_bo *bo, int plane) { return (union gbm_bo_handle){0}; }
int
gbm_bo_get_fd_for_plane(struct gbm_bo *bo, int plane) { return 0; }
int
gbm_bo_write(struct gbm_bo *bo, const void *buf, size_t count) { return 0; }
void
gbm_bo_set_user_data(struct gbm_bo *bo, void *data,
void (*destroy_user_data)(struct gbm_bo *, void *)) {}
void *
gbm_bo_get_user_data(struct gbm_bo *bo) { return 0; }
void
gbm_bo_destroy(struct gbm_bo *bo) {}
struct gbm_surface *
gbm_surface_create(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format, uint32_t flags) { return 0; }
struct gbm_surface *
gbm_surface_create_with_modifiers(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format,
const uint64_t *modifiers,
const unsigned int count) { return 0; }
struct gbm_surface *
gbm_surface_create_with_modifiers2(struct gbm_device *gbm,
uint32_t width, uint32_t height,
uint32_t format,
const uint64_t *modifiers,
const unsigned int count,
uint32_t flags) { return 0; }
struct gbm_bo *
gbm_surface_lock_front_buffer(struct gbm_surface *surface) { return 0; }
void
gbm_surface_release_buffer(struct gbm_surface *surface, struct gbm_bo *bo) {}
int
gbm_surface_has_free_buffers(struct gbm_surface *surface) { return 0; }
void
gbm_surface_destroy(struct gbm_surface *surface) {}
char *
gbm_format_get_name(uint32_t gbm_format, struct gbm_format_name_desc *desc) { return 0; }
#ifdef __cplusplus
}
#endif
#endif
