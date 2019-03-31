/* ------------------------------------------------------------
name: "delaycomp"
Code generated with Faust 2.15.10 (https://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __delaycompdsp_H__
#define  __delaycompdsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>
#include "faust/dsp/dsp.h"
#include "faust/gui/UI.h"
#include "faust/gui/meta.h"

#ifndef FAUSTCLASS 
#define FAUSTCLASS delaycompdsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class delaycompdsp : public dsp {
	
 private:
	
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	int IOTA;
	float fVec0[65536];
	float fConst2;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	float fRec1[2];
	FAUSTFLOAT fHslider4;
	float fRec0[2];
	float fVec1[65536];
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzer.lib/name", "Faust Analyzer Library");
		m->declare("analyzer.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("compressor.lib/name", "Faust Compressor Effect Library");
		m->declare("compressor.lib/version", "0.0");
		m->declare("delay.lib/name", "Faust Delay Library");
		m->declare("delay.lib/version", "0.0");
		m->declare("filename", "delaycomp");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("name", "delaycomp");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 2;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (0.00100000005f * fConst0);
		fConst2 = (2000.0f / fConst0);
		fConst3 = (1000.0f / fConst0);
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.01f);
		fHslider1 = FAUSTFLOAT(1.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(-10.0f);
		
	}
	
	virtual void instanceClear() {
		IOTA = 0;
		for (int l0 = 0; (l0 < 65536); l0 = (l0 + 1)) {
			fVec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec2[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec0[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 65536); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec3[l7] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual delaycompdsp* clone() {
		return new delaycompdsp();
	}
	
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("params");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "unit", "ms");
		ui_interface->addHorizontalSlider("attack", &fHslider1, 1.0f, 0.0f, 1000.0f, 0.00999999978f);
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->declare(&fHslider0, "unit", "ms");
		ui_interface->addHorizontalSlider("delaytime", &fHslider0, 0.00999999978f, 0.0f, 500.0f, 0.00100000005f);
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "unit", "1_to_n");
		ui_interface->addHorizontalSlider("ratio", &fHslider2, 1.0f, 1.0f, 100.0f, 0.00999999978f);
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("release", &fHslider3, 1.0f, 0.0f, 1000.0f, 0.00999999978f);
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("threshold", &fHslider4, -10.0f, -70.0f, 0.0f, 0.00999999978f);
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (fConst1 * float(fHslider0));
		float fSlow1 = std::floor(fSlow0);
		float fSlow2 = (fSlow1 + (1.0f - fSlow0));
		int iSlow3 = int(fSlow0);
		int iSlow4 = (iSlow3 & 65535);
		float fSlow5 = (fSlow0 - fSlow1);
		int iSlow6 = ((iSlow3 + 1) & 65535);
		float fSlow7 = float(fHslider1);
		float fSlow8 = std::exp((0.0f - (fConst2 / fSlow7)));
		float fSlow9 = (((1.0f / float(fHslider2)) + -1.0f) * (1.0f - fSlow8));
		float fSlow10 = std::exp((0.0f - (fConst3 / fSlow7)));
		float fSlow11 = std::exp((0.0f - (fConst3 / float(fHslider3))));
		float fSlow12 = float(fHslider4);
		for (int i = 0; (i < count); i = (i + 1)) {
			float fTemp0 = float(input0[i]);
			fVec0[(IOTA & 65535)] = fTemp0;
			float fTemp1 = std::fabs(fTemp0);
			float fTemp2 = ((fRec1[1] > fTemp1)?fSlow11:fSlow10);
			fRec2[0] = ((fRec2[1] * fTemp2) + (fTemp1 * (1.0f - fTemp2)));
			fRec1[0] = fRec2[0];
			fRec0[0] = ((fSlow8 * fRec0[1]) + (fSlow9 * std::max<float>(((20.0f * std::log10(fRec1[0])) - fSlow12), 0.0f)));
			output0[i] = FAUSTFLOAT((((fSlow2 * fVec0[((IOTA - iSlow4) & 65535)]) + (fSlow5 * fVec0[((IOTA - iSlow6) & 65535)])) * std::pow(10.0f, (0.0500000007f * fRec0[0]))));
			float fTemp3 = float(input1[i]);
			fVec1[(IOTA & 65535)] = fTemp3;
			float fTemp4 = std::fabs(fTemp3);
			float fTemp5 = ((fRec4[1] > fTemp4)?fSlow11:fSlow10);
			fRec5[0] = ((fRec5[1] * fTemp5) + ((1.0f - fTemp5) * fTemp4));
			fRec4[0] = fRec5[0];
			fRec3[0] = ((fSlow8 * fRec3[1]) + (fSlow9 * std::max<float>(((20.0f * std::log10(fRec4[0])) - fSlow12), 0.0f)));
			output1[i] = FAUSTFLOAT((((fSlow2 * fVec1[((IOTA - iSlow4) & 65535)]) + (fSlow5 * fVec1[((IOTA - iSlow6) & 65535)])) * std::pow(10.0f, (0.0500000007f * fRec3[0]))));
			IOTA = (IOTA + 1);
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec0[1] = fRec0[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			
		}
		
	}

};

#endif
