/**
 *  @copyright Copyright 2018 The J-PET Framework Authors. All rights reserved.
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
 *  @file main.cpp
 */

#include <JPetManager/JPetManager.h>
#include "../LargeBarrelAnalysis/TimeWindowCreator.h"
#include "../LargeBarrelAnalysis/SignalFinder.h"
#include "../LargeBarrelAnalysis/SignalTransformer.h"
#include "../LargeBarrelAnalysis/HitFinder.h"
#include "../LargeBarrelAnalysis/EventFinder.h"
#include "../LargeBarrelAnalysis/EventCategorizer.h"
#include "TOTPlotter.h"
#include "OPSCandidateFinder.h"
#include "OPSReconstructor.h"
#include "OPSAnalyzer.h"
#include "OPSCleaner.h"
#include "Ntupler.h"

using namespace std;

int main(int argc, const char* argv[])
{
  JPetManager& manager = JPetManager::getManager();

  manager.registerTask<TimeWindowCreator>("TimeWindowCreator");
  manager.registerTask<SignalFinder>("SignalFinder"); 
  manager.registerTask<SignalTransformer>("SignalTransformer"); 
  manager.registerTask<HitFinder>("HitFinder");
  manager.registerTask<TOTPlotter>("TOTPlotter");
  manager.registerTask<EventFinder>("EventFinder");
  manager.registerTask<EventCategorizer>("EventCategorizer");
  manager.registerTask<OPSCandidateFinder>("OPSCandidateFinder");

  manager.registerTask<OPSReconstructor>("OPSReconstructor");
  manager.registerTask<OPSAnalyzer>("OPSAnalyzer");
  manager.registerTask<OPSCleaner>("OPSCleaner");

  manager.registerTask<Ntupler>("Ntupler");
  
  /*
  manager.useTask("TimeWindowCreator", "hld", "tslot.calib");
  manager.useTask("SignalFinder", "tslot.calib", "raw.sig");
  manager.useTask("SignalTransformer", "raw.sig", "phys.sig");
  manager.useTask("HitFinder", "phys.sig", "hits");
  */
  
  // manager.useTask("TOTPlotter", "hits", "hits.plot");
  // manager.useTask("EventFinder", "hits.plot", "pre.evt");
  manager.useTask("EventCategorizer", "unk.evt", "cat.evt");
  manager.useTask("OPSCandidateFinder", "cat.evt", "ops.cand.evt");

  // manager.useTask("OPSReconstructor", "ops.cand.evt", "ops.rec.evt");
  // manager.useTask("OPSAnalyzer", "ops.rec.evt", "ops.ana.evt");
  // manager.useTask("OPSCleaner", "ops.ana.evt", "ops.cln.evt");

  //  manager.useTask("Ntupler", "pre.evt", "void");
  
  manager.run(argc, argv);
}
