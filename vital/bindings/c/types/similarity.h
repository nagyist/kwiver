/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief File description here.
 */

#ifndef VITAL_C_SIMILARITY_H_
#define VITAL_C_SIMILARITY_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <vital/bindings/c/error_handle.h>
#include <vital/bindings/c/types/eigen.h>
#include <vital/bindings/c/types/rotation.h>
#include <vital/bindings/c/vital_c_export.h>


#define DECLARE_TYPED_OPERATIONS( T, S ) \
\
/** Opaque instance type */ \
typedef struct vital_similarity_##S##_s vital_similarity_##S##_t; \
\
/**
 * Create a new similarity instance
 */ \
VITAL_C_EXPORT \
vital_similarity_##S##_t* \
vital_similarity_##S##_new( T s, vital_rotation_##S##_t const *r, \
                            vital_eigen_matrix3x1##S##_t const *t, \
                            vital_error_handle_t *eh ); \
\
/**
 * Create a new similarity instance with default initial value
 */ \
VITAL_C_EXPORT \
vital_similarity_##S##_t* \
vital_similarity_##S##_new_default( vital_error_handle_t *eh ); \
\
/**
 * Destroy a similarity instance
 */ \
VITAL_C_EXPORT \
void \
vital_similarity_##S##_destroy( vital_similarity_##S##_t *s, \
                                vital_error_handle_t *eh ); \
\
/**
 * Get the scale factor of a similarity instance
 */ \
VITAL_C_EXPORT \
T \
vital_similarity_##S##_scale( vital_similarity_##S##_t const *sim, \
                              vital_error_handle_t *eh ); \
\
/**
 * Get the rotation of a similarity instance
 */ \
VITAL_C_EXPORT \
vital_rotation_##S##_t* \
vital_similarity_##S##_rotation( vital_similarity_##S##_t const *sim, \
                                 vital_error_handle_t *eh ); \
\
/**
 * Get the translation of a similarity instance
 */ \
VITAL_C_EXPORT \
vital_eigen_matrix3x1##S##_t* \
vital_similarity_##S##_translation( vital_similarity_##S##_t const *sim, \
                                    vital_error_handle_t *eh ); \
\
/**
 * Compute the inverse of a similarity, returning a new similarity instance
 */ \
VITAL_C_EXPORT \
vital_similarity_##S##_t* \
vital_similarity_##S##_inverse( vital_similarity_##S##_t const *sim, \
                                vital_error_handle_t *eh ); \
\
/**
 * Compose two similarities
 */ \
VITAL_C_EXPORT \
vital_similarity_##S##_t* \
vital_similarity_##S##_compose( vital_similarity_##S##_t const *s_lhs, \
                                vital_similarity_##S##_t const *s_rhs, \
                                vital_error_handle_t *eh ); \
\
/**
 * Transform a vector
 *
 * \note for a large number of vectors, it is more efficient to
 *       create a transform matrix and use matrix multiplication
 */ \
VITAL_C_EXPORT \
vital_eigen_matrix3x1##S##_t* \
vital_similarity_##S##_vector_transform( vital_similarity_##S##_t const *s, \
                                         vital_eigen_matrix3x1##S##_t const *rhs, \
                                         vital_error_handle_t *eh ); \
\
/**
 * Test equality between two similarities
 */ \
VITAL_C_EXPORT \
bool \
vital_similarity_##S##_are_equal( vital_similarity_##S##_t const *s_lhs, \
                                  vital_similarity_##S##_t const *s_rhs, \
                                  vital_error_handle_t *eh ); \
\
/**
 * Convert a similarity into a 4x4 matrix
 */ \
VITAL_C_EXPORT \
vital_eigen_matrix4x4##S##_t* \
vital_similarity_##S##_to_matrix4x4( vital_similarity_##S##_t const *s, \
                                     vital_error_handle_t *eh ); \
\
/**
 * Create a similarity from a 4x4 matrix
 */ \
VITAL_C_EXPORT \
vital_similarity_##S##_t* \
vital_similarity_##S##_from_matrix4x4( vital_eigen_matrix4x4##S##_t const *m, \
                                       vital_error_handle_t *eh );


DECLARE_TYPED_OPERATIONS( double, d );
DECLARE_TYPED_OPERATIONS( float,  f );

#undef DECLARE_TYPED_OPERATIONS


#ifdef __cplusplus
}
#endif

#endif //VITAL_C_SIMILARITY_H_
