#pragma once

#include "IPlug_include_in_plug_hdr.h"
#if IPLUG_DSP
#include "gen_export/gen_dsp.h"
#endif

const int kNumPrograms = 1;
const int kNumParams = 24;

class Fourses : public IPlug
{
public:
  Fourses(IPlugInstanceInfo instanceInfo);
  ~Fourses();
  
#if IPLUG_DSP // All DSP methods and member variables should be within an IPLUG_DSP guard, should you want distributed UI
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  void OnReset() override;
  void OnParamChange(int paramIdx, EParamSource source, int offset) override;
private:
  CommonState* mGenDSPState = nullptr;
#endif
};
