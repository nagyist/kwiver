/*ckwg +29
 * Copyright 2014-2018 by Kitware, Inc.
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
 * \brief Header for core triangulate_landmarks algorithm
 */

#ifndef KWIVER_ARROWS_CORE_TRIANGULATE_LANDMARKS_H_
#define KWIVER_ARROWS_CORE_TRIANGULATE_LANDMARKS_H_

#include <arrows/core/kwiver_algo_core_export.h>

#include <vital/algo/triangulate_landmarks.h>

namespace kwiver {
namespace arrows {
namespace core {

/// A class for triangulating landmarks from feature tracks and cameras using Eigen
class KWIVER_ALGO_CORE_EXPORT triangulate_landmarks
: public vital::algorithm_impl<triangulate_landmarks,
                              vital::algo::triangulate_landmarks>
{
public:
  PLUGIN_INFO( "core",
               "Triangulate landmarks from tracks and cameras"
               " using a simple least squares solver." )

  /// Constructor
  triangulate_landmarks();

  /// Destructor
  virtual ~triangulate_landmarks();

  /// Copy Constructor
  triangulate_landmarks(const triangulate_landmarks& other);

  /// Get this alg's \link vital::config_block configuration block \endlink
  virtual vital::config_block_sptr get_configuration() const;
  /// Set this algo's properties via a config block
  virtual void set_configuration(vital::config_block_sptr config);
  /// Check that the algorithm's currently configuration is valid
  virtual bool check_configuration(vital::config_block_sptr config) const;

  /// Triangulate the landmark locations given sets of cameras and feature tracks
  /**
   * \param [in] cameras the cameras viewing the landmarks
   * \param [in] tracks the feature tracks to use as constraints
   * \param [in,out] landmarks the landmarks to triangulate
   *
   * This function only triangulates the landmarks with indicies in the
   * landmark map and which have support in the tracks and cameras.  Note:
   * triangulate modifies the inlier/outlier flags in tracks. It also sets
   * the cosine of the maximum observation angle and number of observations
   * in the landmarks.
   */
  virtual void
  triangulate(vital::camera_map_sptr cameras,
              vital::feature_track_set_sptr tracks,
              vital::landmark_map_sptr& landmarks) const;


  /// Triangulate the landmark locations given sets of cameras and feature tracks
  /**
  * \param [in] cameras the cameras viewing the landmarks
  * \param [in] tracks the feature tracks to use as constraints in a map
  * \param [in,out] landmarks the landmarks to triangulate
  *
  * This function only triangulates the landmarks with indicies in the
  * landmark map and which have support in the tracks and cameras.  Note:
  * triangulate modifies the inlier/outlier flags in tracks. It also sets
  * the cosine of the maximum observation angle and number of observations
  * in the landmarks.
  */
  virtual void
  triangulate(vital::camera_map_sptr cameras,
              vital::track_map_t tracks,
              vital::landmark_map_sptr& landmarks) const;

private:
  /// private implementation class
  class priv;
  const std::unique_ptr<priv> d_;
};

typedef std::shared_ptr<triangulate_landmarks> triangulate_landmarks_sptr;

} // end namespace core
} // end namespace arrows
} // end namespace kwiver

#endif // KWIVER_ARROWS_CORE_TRIANGULATE_LANDMARKS_H_
