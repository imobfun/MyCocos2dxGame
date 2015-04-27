//
//  DeathUI.cpp
//  TinyFlare
//
//  Created by wang haibo on 15/4/27.
//
//

#include "DeathUI.h"
#include "UtilityHelper.h"
#include "GameController.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

DeathUI* DeathUI::create()
{
    DeathUI *pRet = new(std::nothrow) DeathUI();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

DeathUI::DeathUI()
{
    m_pPlayGameBtn      = nullptr;
    m_pRemoveADSBtn     = nullptr;
//    m_pRankBtn          = nullptr;
//    m_pShareBtn         = nullptr;
    m_pHelpBtn          = nullptr;
    m_pBackBtn          = nullptr;
    m_pMenuBg           = nullptr;
    m_pGameTitle        = nullptr;
    m_pPlayText         = nullptr;
}
DeathUI::~DeathUI()
{
}
bool DeathUI::init()
{
    auto size = Director::getInstance()->getVisibleSize();
    float scale = size.height/640.0f;
    m_pMenuBg = ui::ImageView::create("menubg.png");
    if(!m_pMenuBg)
        return false;
    m_pMenuBg->setScale9Enabled(true);
    m_pMenuBg->setCapInsets(Rect(0,1,128,2));
    m_pMenuBg->setContentSize(Size(size.width,size.height*0.3f));
    m_pMenuBg->setPosition(Vec2(size.width*0.5f, size.height*0.65f));
    m_pMenuBg->setScale(0);
    addChild(m_pMenuBg);
    
    ScaleTo* scaleTo1 = ScaleTo::create(0.2f, 0, 1.0f);
    ScaleTo* scaleTo2 = ScaleTo::create(0.2f, 1.0f, 1.0f);
    Spawn* spawn = Spawn::createWithTwoActions(scaleTo1, scaleTo2);
    m_pMenuBg->runAction(spawn);
    
    m_pGameTitle = ui::Text::create(UtilityHelper::getLocalString("DEAD"), "FZXS12.TTF", size.height*0.1f);
    if(!m_pGameTitle)
        return false;
    m_pGameTitle->setPosition(Vec2(size.width*1.5f, size.height*0.65f));
    m_pGameTitle->setColor(Color3B(208,255,208));
    addChild(m_pGameTitle);
    
    DelayTime* delay = DelayTime::create(0.2f);
    MoveTo* moveTo = MoveTo::create(0.2f, Vec2(size.width*0.5f, size.height*0.65f));
    Sequence* sequence = Sequence::createWithTwoActions(delay, moveTo);
    m_pGameTitle->runAction(sequence);
    
    m_pPlayGameBtn = ui::Button::create("menubg.png");
    if(!m_pPlayGameBtn)
        return false;
    m_pPlayGameBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressContinueGameBtn, this));
    m_pPlayGameBtn->setScale9Enabled(true);
    m_pPlayGameBtn->setCapInsets(Rect(0,2,128,0.5f));
    m_pPlayGameBtn->setContentSize(Size(size.width,size.height*0.1f));
    m_pPlayGameBtn->setPosition(Vec2(size.width*0.5f, size.height*0.3f));
    m_pPlayGameBtn->setScale(0);
    addChild(m_pPlayGameBtn);
    
    Sequence* sequence2 = Sequence::createWithTwoActions(delay, spawn);
    m_pPlayGameBtn->runAction(sequence2);
    
    m_pPlayText = ui::Text::create(UtilityHelper::getLocalString("PRESS_CONTINUE"), "FZXS12.TTF", size.height*0.05f);
    if(!m_pPlayText)
        return false;
    m_pPlayText->setPosition(Size(size.width*0.5f,size.height*0.3f));
    m_pPlayText->setOpacity(0);
    m_pPlayText->setColor(Color3B(208,255,208));
    addChild(m_pPlayText);
    
    EaseSineOut* easeOut1 = EaseSineOut::create(FadeIn::create(0.5f));
    EaseSineOut* easeOut2 = EaseSineOut::create(FadeOut::create(0.5f));
    Sequence* sequence3 = Sequence::create(easeOut1, delay, easeOut2, NULL);
    RepeatForever* repeat = RepeatForever::create(sequence3);
    m_pPlayText->runAction(repeat);
    
    m_pRemoveADSBtn = ui::Button::create("removeads.png");
    if(!m_pRemoveADSBtn)
        return false;
    m_pRemoveADSBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressRemoveADSBtn, this));
    m_pRemoveADSBtn->setPosition(Vec2(size.width - m_pRemoveADSBtn->getContentSize().width*scale*2.1f, size.height*0.1f));
    m_pRemoveADSBtn->setScale(0.4f*scale);
    addChild(m_pRemoveADSBtn);
    
//    m_pRankBtn = ui::Button::create("rank.png");
//    if(!m_pRankBtn)
//        return false;
//    m_pRankBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressRankBtn, this));
//    m_pRankBtn->setPosition(Vec2(size.width - m_pRankBtn->getContentSize().width*scale*0.7f, size.height*0.1f));
//    m_pRankBtn->setScale(0.4f*scale);
//    addChild(m_pRankBtn);
//    
//    m_pShareBtn = ui::Button::create("share.png");
//    if(!m_pShareBtn)
//        return false;
//    m_pShareBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressShareBtn, this));
//    m_pShareBtn->setPosition(Vec2(size.width - m_pShareBtn->getContentSize().width*scale*0.7f, size.height*0.1f));
//    m_pShareBtn->setScale(0.4f*scale);
//    addChild(m_pShareBtn);
    
    m_pHelpBtn = ui::Button::create("help.png");
    if(!m_pHelpBtn)
        return false;
    m_pHelpBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressHelpBtn, this));
    m_pHelpBtn->setPosition(Vec2(size.width - m_pHelpBtn->getContentSize().width*scale*1.4f, size.height*0.1f));
    m_pHelpBtn->setScale(0.4f*scale);
    addChild(m_pHelpBtn);
    
    m_pBackBtn = ui::Button::create("exit.png");
    if(!m_pBackBtn)
        return false;
    m_pBackBtn->addTouchEventListener(CC_CALLBACK_2(DeathUI::pressBackBtn, this));
    m_pBackBtn->setPosition(Vec2(size.width - m_pBackBtn->getContentSize().width*scale*0.7f, size.height*0.1f));
    m_pBackBtn->setScale(0.4f*scale);
    addChild(m_pBackBtn);
    return true;
}
void DeathUI::pressContinueGameBtn(Ref* p,TouchEventType eventType)
{
    if(eventType == TouchEventType::ENDED)
    {
        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
        GameController::getInstance()->setGameState(GS_GAME);
    }
}
void DeathUI::pressRemoveADSBtn(Ref* p,TouchEventType eventType)
{
    if(eventType == TouchEventType::ENDED)
    {
        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
    }
}
//void DeathUI::pressRankBtn(Ref* p,TouchEventType eventType)
//{
//    if(eventType == TouchEventType::ENDED)
//    {
//        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
//    }
//}
//void DeathUI::pressShareBtn(Ref* p,TouchEventType eventType)
//{
//    if(eventType == TouchEventType::ENDED)
//    {
//        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
//    }
//}
void DeathUI::pressHelpBtn(Ref* p,TouchEventType eventType)
{
    if(eventType == TouchEventType::ENDED)
    {
        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
    }
}
void DeathUI::pressBackBtn(Ref* p,TouchEventType eventType)
{
    if(eventType == TouchEventType::ENDED)
    {
        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
        GameController::getInstance()->setGameState(GS_MENU);
    }
}
void DeathUI::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *unused_event)
{
    if(keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        SimpleAudioEngine::getInstance()->playEffect("btnclick.wav");
        GameController::getInstance()->setGameState(GS_MENU);
    }
}