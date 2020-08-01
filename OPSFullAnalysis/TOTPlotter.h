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
 *  @file EventFinder.h
 */

#ifndef TOTPLOTTER_H 
#define TOTPLOTTER_H 

#include <vector>
#include <map>
#include <JPetUserTask/JPetUserTask.h>
#include <JPetHit/JPetHit.h>

class JPetWriter;

#ifdef __CINT__
#	define override
#endif

class TOTPlotter : public JPetUserTask{
public:
  TOTPlotter(const char * name);
  virtual ~TOTPlotter(){}
  virtual bool init() override;
  virtual bool exec() override;
  virtual bool terminate() override;

protected:
  bool fIsMC = false;
  std::vector<JPetHit> fHitVector;
  JPetHit calculateTOT(const JPetHit& hit);

  const std::string fEventTimeParamKey = "OPSFinder_FineEventTime_float";

  const std::vector<std::string> fTOTcutKeys = {
    "OPSFinder_TOTanh_low_float",
    "OPSFinder_TOTanh_high_float",
    "OPSFinder_TOTdex_low_float",
    "OPSFinder_TOTdex_high_float"
  };

  const std::vector<std::string> fEdepMCcutKeys = {
    "OPSFinder_MC_Edep_anh_low_float",
    "OPSFinder_MC_Edep_anh_high_float",
    "OPSFinder_MC_Edep_dex_low_float",
    "OPSFinder_MC_Edep_dex_high_float"
  };

  std::vector<double> fTOTcuts;
  std::vector<double> fMCEdepCuts;

};
#endif /*  !TOTPLOTTER  */
