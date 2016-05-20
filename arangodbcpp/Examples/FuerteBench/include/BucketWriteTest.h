////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author John Bufton
////////////////////////////////////////////////////////////////////////////////

#ifndef BUCKETWRITETEST_H
#define BUCKETWRITETEST_H

#include "BucketTest.h"

#include <velocypack/Buffer.h>
#include <velocypack/Builder.h>
#include <velocypack/Parser.h>

#include <atomic>

class BucketWriteTest : public BucketTest {
 public:
  typedef arangodb::velocypack::Buffer<uint8_t> VBuffer;
  typedef arangodb::velocypack::Builder Builder;
  typedef std::shared_ptr<VBuffer> VPack;
  typedef std::vector<VPack> DocBodies;

  BucketWriteTest() = delete;
  BucketWriteTest(const std::string& hostName, const std::string& dbName,
                  const std::string& colName, Connection::Protocol prot);

  void setDocBodies(DocDatas::const_iterator iFirst,
                    DocDatas::const_iterator iEnd);

  void operator()(std::atomic_bool& bWait, LoopCount loops) override final;

 private:
  Document::SPtr _document;
  DocBodies::const_iterator _iFirst;
  DocBodies::const_iterator _iEnd;
  DocBodies _bodies;
};

#endif
