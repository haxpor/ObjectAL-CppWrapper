//
//  OALSimpleAudioCppWrapper.mm
//  ObjectAL-CppWrapper
//
//  Created by haxpor on 10/30/15.
//
//

#include "OALSimpleAudioCppWrapper.h"
#include "OALSimpleAudio.h"

static OALSimpleAudioCppWrapper* _singleton;

OALSimpleAudioCppWrapper::OALSimpleAudioCppWrapper()
{
}

void OALSimpleAudioCppWrapper::init()
{
    // nothing to do here right now
    [OALSimpleAudio sharedInstance].paused = NO;
    [OALSimpleAudio sharedInstance].allowIpod = NO;
    [OALSimpleAudio sharedInstance].honorSilentSwitch = YES;
}

void OALSimpleAudioCppWrapper::preloadEffect(const char* filePath)
{
    [[OALSimpleAudio sharedInstance] preloadEffect:[NSString stringWithUTF8String:filePath]];
}

void OALSimpleAudioCppWrapper::playBg()
{
    [[OALSimpleAudio sharedInstance] playBg];
}

void OALSimpleAudioCppWrapper::playBg(const char* filePath, bool loop)
{
    [[OALSimpleAudio sharedInstance] playBg:[NSString stringWithUTF8String:filePath] loop:loop ? YES : NO];
}

void OALSimpleAudioCppWrapper::stopAllEffects()
{
    [[OALSimpleAudio sharedInstance] stopAllEffects];
}

void OALSimpleAudioCppWrapper::playEffect(const char* filePath)
{
    [[OALSimpleAudio sharedInstance] playEffect:[NSString stringWithUTF8String:filePath]];
}

void OALSimpleAudioCppWrapper::stopEverything()
{
    [[OALSimpleAudio sharedInstance] stopEverything];
}

void OALSimpleAudioCppWrapper::unloadAllEffects()
{
    [[OALSimpleAudio sharedInstance] unloadAllEffects];
}

void OALSimpleAudioCppWrapper::setAllowIpod(bool allow)
{
    [OALSimpleAudio sharedInstance].allowIpod = allow;
}
bool OALSimpleAudioCppWrapper::getAllowIpod()
{
    return [OALSimpleAudio sharedInstance].allowIpod;
}

void OALSimpleAudioCppWrapper::setHonorSilentSwitch(bool honor)
{
    [OALSimpleAudio sharedInstance].honorSilentSwitch = honor;
}
bool OALSimpleAudioCppWrapper::getHonorSilentSwitch()
{
    return [OALSimpleAudio sharedInstance].honorSilentSwitch;
}

void OALSimpleAudioCppWrapper::setPaused(bool paused)
{
    [OALSimpleAudio sharedInstance].paused = paused;
}
bool OALSimpleAudioCppWrapper::getPaused()
{
    return [OALSimpleAudio sharedInstance].paused;
}

OALSimpleAudioCppWrapper* OALSimpleAudioCppWrapper::sharedInstance() {
    static bool s_isFirstUsed = true;
    if (s_isFirstUsed)
    {
        s_isFirstUsed = false;
        _singleton = new OALSimpleAudioCppWrapper();
        _singleton->init();
    }
    
    return _singleton;
}
