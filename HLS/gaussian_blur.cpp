#include "stream_header.h"

void gaussian_blur_compressed(stream_t& stream_in, stream_t& stream_out) {
    int const rows = MAX_HEIGHT;
    int const cols = MAX_WIDTH;

    rgb_img_t img0(rows, cols);
    rgb_img_t img1(rows, cols);

    hls::AXIvideo2Mat(stream_in, img0);
    #pragma HLS ALLOCATION instances=mul limit=1 operation
    hls::GaussianBlur<3, 3>(img0, img1, (double)1.5, (double)1.5);
    hls::Mat2AXIvideo(img1, stream_out);
}
