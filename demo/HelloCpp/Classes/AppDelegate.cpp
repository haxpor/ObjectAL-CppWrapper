/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "AppDelegate.h"

#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	CCSize frameSize = pEGLView->getFrameSize();
    
    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    TargetPlatform target = getTargetPlatform();
    if(target == kTargetIpad)
    {
        // ipad
        if(pDirector->enableRetinaDisplay(true))
        {
            // ipad hd
            CCFileUtils::sharedFileUtils()->setResourceDirectory("ipadhd");
        }
        else
        {
            CCFileUtils::sharedFileUtils()->setResourceDirectory("ipad");
        }
    }
    else if(target == kTargetIphone)
    {
        // iphone
        if(pDirector->enableRetinaDisplay(true))
        {
            if(pDirector->getWinSize().width > 480)
            {
                // iphone hd 4'
                CCFileUtils::sharedFileUtils()->setResourceDirectory("iphone");
            }
            else
            {
                // iphone hd 3'
                CCFileUtils::sharedFileUtils()->setResourceDirectory("iphone");
            }
        }
    }
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
