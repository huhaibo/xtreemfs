// Copyright (c) 2010 NEC HPC Europe
// All rights reserved
// 
// This source file is part of the XtreemFS project.
// It is licensed under the New BSD license:
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// * Neither the name of the XtreemFS project nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL NEC HPC Europe BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#ifndef _LIBXTREEMFS_FILE_H_
#define _LIBXTREEMFS_FILE_H_

#include "xtreemfs/osd_proxy.h"


namespace xtreemfs
{
  class Volume;
  using org::xtreemfs::interfaces::Lock;
  using org::xtreemfs::interfaces::XCap;
  using org::xtreemfs::interfaces::XLocSet;
  using yield::platform::Path;


  class File : public yield::platform::File
  {
  public:
    File
    (
      Volume& parent_volume,
      const Path& path,
      const XCap& xcap,
      const XLocSet& xlocs
    );

    ~File();

    const Path& get_path() const { return path; }
    const XCap& get_xcap() const { return xcap; }
    const XLocSet& get_xlocs() const { return xlocs; }

    // yidl::runtime::Object
    File& inc_ref() { return Object::inc_ref( *this ); }

    // yield::platform::File
    YIELD_PLATFORM_FILE_PROTOTYPES;
    size_t getpagesize();

  private:
    class Buffer;
    class XCapTimer;

  private:
    bool closed;
    vector<Lock> locks;
    Volume& parent_volume;
    Path path;
    size_t selected_file_replica_i;
    XCap xcap;
    XCapTimer* xcap_timer;
    XLocSet xlocs;
  };
};

#endif