/*ckwg +5
 * Copyright 2011-2012 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef VISTK_PROCESSES_IMAGE_IMAGE_WRITER_PROCESS_H
#define VISTK_PROCESSES_IMAGE_IMAGE_WRITER_PROCESS_H

#include "image-config.h"

#include <vistk/pipeline/process.h>

#include <boost/scoped_ptr.hpp>

/**
 * \file image_writer_process.h
 *
 * \brief Declaration of the image writer process.
 */

namespace vistk
{

/**
 * \class image_writer_process
 *
 * \brief A process for writing images to files.
 *
 * \process Write images to files.
 *
 * \iports
 *
 * \iport{image} The image to write.
 *
 * \oports
 *
 * \oport{path} The path written to.
 *
 * \configs
 *
 * \config{pixtype} The pixel type of the input images.
 * \config{pixfmt} The pixel format of the input images.
 * \config{format} The format for the output file names. The format string is
 *                 passed two parameters:
 *                   1) the name of the process
 *                   2) The step count (0 indexed)
 *
 * \reqs
 *
 * \req The \port{image} port must be connected.
 * \req The \key{format} configuration must generate valid filepaths.
 *
 * \ingroup process_image
 */
class VISTK_PROCESSES_IMAGE_NO_EXPORT image_writer_process
  : public process
{
  public:
    /**
     * \brief Constructor.
     *
     * \param config The configuration for the process.
     */
    image_writer_process(config_t const& config);
    /**
     * \brief Destructor.
     */
    ~image_writer_process();
  protected:
    /**
     * \brief Configure the process.
     */
    void _configure();

    /**
     * \brief Reset the process.
     */
    void _reset();

    /**
     * \brief Step the process.
     */
    void _step();
  private:
    class priv;
    boost::scoped_ptr<priv> d;
};

}

#endif // VISTK_PROCESSES_IMAGE_IMAGE_WRITER_PROCESS_H
