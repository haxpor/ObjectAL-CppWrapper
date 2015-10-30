//
//  OALSimpleAudioCppWrapper.h
//  ObjectAL-CppWrapper
//
//  Created by haxpor on 10/30/15.
//
//

#ifndef __ObjectAL_CppWrapper__OALSimpleAudioCppWrapper__
#define __ObjectAL_CppWrapper__OALSimpleAudioCppWrapper__

class OALSimpleAudioCppWrapper {
    
private:
	OALSimpleAudioCppWrapper();

public:
	void preloadEffect(const char* filePath);
	void playBg();
	void playBg(const char* filePath, bool loop=true);
	void stopAllEffects();
	void playEffect(const char* filePath);
	void stopEverything();
	void unloadAllEffects();

	void setAllowIpod(bool allow);
    bool getAllowIpod();
    
	void setHonorSilentSwitch(bool honor);
    bool getHonorSilentSwitch();
    
	void setPaused(bool paused);
    bool getPaused();

	static OALSimpleAudioCppWrapper* sharedInstance();
    
protected:
    void init();
};

#endif