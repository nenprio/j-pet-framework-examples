/**
 *  @copyright Copyright 2016 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  @file OPSReconstructor.h
 */

#ifndef OPSRECONSTRUCTOR_H 
#define OPSRECONSTRUCTOR_H 

#include <vector>
#include <map>
#include <JPetUserTask/JPetUserTask.h>
#include <JPetHit/JPetHit.h>
#include <JPetEvent/JPetEvent.h>
#include "reconstructor.h"

class JPetWriter;

#ifdef __CINT__
#	define override
#endif

class OPSReconstructor : public JPetUserTask{
public:
  OPSReconstructor(const char * name);
  virtual ~OPSReconstructor(){}
  virtual bool init() override;
  virtual bool exec() override;
  virtual bool terminate() override;
protected:
  bool fIsMC = false;
  Reconstructor * fReconstructor;  
  const std::string fTimeRecalibFileKey = "OPSReconstructor_TimeRecalibFile_std::string";
  std::string fTimeRecalibFile = "";
  bool fShouldRecalibrateTimes = false;
  std::vector<double> fTimeRecalibConstants;
};
#endif /*  !OPSRECONSTRUCTOR_H */










