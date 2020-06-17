/* Usage
    #define LCG_BUFFERS_IMPLEMENTATION
*/
#ifndef LCG_BUFFERS_H
#define LCG_BUFFERS_H
#include <GL/glew.h>

// Vertex Buffer
typedef struct{
    GLuint renderer_id;
}lcg_vb; 

lcg_vb* lcg_vb_create(const void* data, GLuint size);
void vbuffer_bind(vertex_buffer vb);
void vbuffer_unbind(vertex_buffer vb);
void vbuffer_destroy(vertex_buffer* vb);
#ifdef LCG_BUFFERS_IMPLEMENTATION

#endif // LCG_BUFFERS_IMPLEMENTATION
#endif // LCG_BUFFERS_H