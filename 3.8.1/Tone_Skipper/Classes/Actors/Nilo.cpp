//
//  Nilo.cpp
//  Tone_Skipper
//
//  Created by wang haibo on 15/8/27.
//
//

#include "Nilo.h"
#include "MapMgrs.h"
USING_NS_CC;

Nilo::Nilo()
{
    m_PlayerType = PT_NILO;
}
Nilo::~Nilo()
{
}
bool Nilo::loadModel()
{
    bool ret = true;
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_red.plist");
    m_pSprite = HueSprite::createWithSpriteFrameName("red_idle_01.png");
    if(!m_pSprite)
    {
        CCLOG("Nilo : Load model failed!");
        ret = false;
    }
    m_pSprite->setAnchorPoint(Vec2(0.5f,0));
    addChild(m_pSprite);
#if COCOS2D_DEBUG
    showDebug(true);
#endif
    return ret;
}
bool Nilo::loadAnimations()
{
    bool ret = true;
    ///idle
    m_pIdleAnimation = AnimationCache::getInstance()->getAnimation("nilo_idle");
    if(!m_pIdleAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = nullptr;
        for (int i = 0; i<10; i++) {
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
            if(!frame)
                ret = false;
            arrayOfAnimation.pushBack(frame);
        }
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        m_pIdleAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pIdleAnimation)
            ret = false;
        
        m_pIdleAnimation->setDelayPerUnit(3.0f / 15.0f);
        AnimationCache::getInstance()->addAnimation(m_pIdleAnimation, "nilo_idle");
    }
    ///run
    m_pRunAnimation = AnimationCache::getInstance()->getAnimation("nilo_run");
    if(!m_pRunAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_run_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_run_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        m_pRunAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pRunAnimation)
            ret = false;
        
        m_pRunAnimation->setDelayPerUnit(0.3f / 2.0f);
        AnimationCache::getInstance()->addAnimation(m_pRunAnimation, "nilo_run");
    }
    ///jump
    m_pJumpAnimation = AnimationCache::getInstance()->getAnimation("nilo_jump");
    if(!m_pJumpAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_jump.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pJumpAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pJumpAnimation)
            ret = false;
        
        m_pJumpAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pJumpAnimation, "nilo_jump");
    }
    ///superjump
    m_pSuperJumpAnimation = AnimationCache::getInstance()->getAnimation("nilo_superjump");
    if(!m_pSuperJumpAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_superjump.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pSuperJumpAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pSuperJumpAnimation)
            ret = false;
        
        m_pSuperJumpAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pSuperJumpAnimation, "nilo_superjump");
    }
    
    ///shakehead
    m_pShakeHeadAnimation = AnimationCache::getInstance()->getAnimation("nilo_shakehead");
    if(!m_pShakeHeadAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pShakeHeadAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pShakeHeadAnimation)
            ret = false;
        
        m_pShakeHeadAnimation->setDelayPerUnit(0.4f / 4.0f);
        AnimationCache::getInstance()->addAnimation(m_pShakeHeadAnimation, "nilo_shakehead");
    }

    ///turnback
    m_pTurnBackAnimation = AnimationCache::getInstance()->getAnimation("nilo_turnback");
    if(!m_pTurnBackAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_03.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_04.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_05.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_turn_back_06.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pTurnBackAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pTurnBackAnimation)
            ret = false;
        
        m_pTurnBackAnimation->setDelayPerUnit(0.3f / 6.0f);
        AnimationCache::getInstance()->addAnimation(m_pTurnBackAnimation, "nilo_turnback");
    }

    ///back idle
    m_pBackIdleAnimation = AnimationCache::getInstance()->getAnimation("nilo_backidle");
    if(!m_pBackIdleAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_idle_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pBackIdleAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pBackIdleAnimation)
            ret = false;
        
        m_pBackIdleAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pBackIdleAnimation, "nilo_backidle");
    }

    ///back fire run
    m_pBackFireRunAnimation = AnimationCache::getInstance()->getAnimation("nilo_backfire_run");
    if(!m_pBackFireRunAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_fire_run_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_fire_run_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        m_pBackFireRunAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pBackFireRunAnimation)
            ret = false;
        
        m_pBackFireRunAnimation->setDelayPerUnit(0.3f / 2.0f);
        AnimationCache::getInstance()->addAnimation(m_pBackFireRunAnimation, "nilo_backfire_run");
    }

    ///backjump
    m_pBackJumpAnimation = AnimationCache::getInstance()->getAnimation("nilo_backjump");
    if(!m_pBackJumpAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_fire_jump.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pBackJumpAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pBackJumpAnimation)
            ret = false;
        
        m_pBackJumpAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pBackJumpAnimation, "nilo_backjump");
    }
    ///superjump
    m_pBackSuperJumpAnimation = AnimationCache::getInstance()->getAnimation("nilo_backsuperjump");
    if(!m_pBackSuperJumpAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_fire_superjump.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pBackSuperJumpAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pBackSuperJumpAnimation)
            ret = false;
        
        m_pBackSuperJumpAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pBackSuperJumpAnimation, "nilo_backsuperjump");
    }

    ///back run
    m_pBackForwardRunAnimation = AnimationCache::getInstance()->getAnimation("nilo_backrun");
    if(!m_pBackForwardRunAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_run_01.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_back_run_02.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        m_pBackForwardRunAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pBackForwardRunAnimation)
            ret = false;
        
        m_pBackForwardRunAnimation->setDelayPerUnit(0.3f / 2.0f);
        AnimationCache::getInstance()->addAnimation(m_pBackForwardRunAnimation, "nilo_backrun");
    }

    
    ///squat
    m_pSquatAnimation = AnimationCache::getInstance()->getAnimation("nilo_squat");
    if(!m_pSquatAnimation)
    {
        Vector<SpriteFrame*> arrayOfAnimation;
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("red_squat.png");
        if(!frame)
            ret = false;
        arrayOfAnimation.pushBack(frame);
        
        m_pSquatAnimation = Animation::createWithSpriteFrames(arrayOfAnimation);
        if(!m_pSquatAnimation)
            ret = false;
        
        m_pSquatAnimation->setDelayPerUnit(0.2f / 1.0f);
        AnimationCache::getInstance()->addAnimation(m_pSquatAnimation, "nilo_squat");
    }

    if(!ret)
        CCLOG("Nilo : Load animations failed!");
    return ret;
}
void Nilo::onLand()
{
    if(getPlayerDirection() != PD_BACK)
    {
        if(m_bLeftBtnPressed || m_bRightBtnPressed)
            setPlayerState(PS_RUN);
        else
        {
            if(!m_bDownBtnPressed)
                setPlayerState(PS_IDLE);
            else
                setPlayerState(PS_SQUAT);
        }
    }
    else
    {
        if(!m_bOnLadder)
            setPlayerState(PS_TURNFRONT);
    }
}
void Nilo::onLeftBtnPressed()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
    m_bLeftBtnPressed = true;
    if(getPlayerDirection() != PD_BACK)
        setPlayerDirection(PD_LEFT);
    setPlayerState(PS_RUN);
}
void Nilo::onLeftBtnReleased()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
    m_bLeftBtnPressed = false;
    if(m_bOnLand)
    {
        if(!m_bRightBtnPressed)
            setPlayerState(PS_IDLE);
        else
            setPlayerDirection(PD_RIGHT);
    }
    else
    {
        if(m_bRightBtnPressed)
            setPlayerDirection(PD_RIGHT);
    }
}
void Nilo::onUpBtnPressed()
{
    if(!m_bAcceptInput)
        return;
    if(getPlayerState() != PS_IDLE)
        return;
    m_bUpBtnPressed = true;
    cocos2d::Rect rect = getBoundingBox();
    rect.origin += getPosition() + Vec2(0, m_fMaxYSpeed);
    UsableItem::USABLE_ITEM_TYPE type = UsableItem::UIT_UNKNOWN;
    bool available = MapMgrs::getInstance()->checkUsableItems(rect, type);
    if(available)
    {
        switch (type) {
            case UsableItem::UIT_LADDER:
                {
                    m_bOnLadder = true;
                    if(m_PlayerDirection != PD_BACK)
                        setPlayerState(PS_TURNBACK);
                    else
                        setPlayerState(PS_BACKFORWARDRUN);
                }
                break;
            case UsableItem::UIT_QUESTION_MARK:
                {
                    
                }
                break;
            default:
                break;
        }
    }
    else
    {
        if(m_PlayerDirection == PD_BACK && m_bOnLadder)
            setPlayerState(PS_BACKFORWARDRUN);
        else
            setPlayerState(PS_SHAKEHEAD);
    }
}
void Nilo::onUpBtnReleased()
{
    if(!m_bAcceptInput)
        return;
    m_bUpBtnPressed = false;
    
    if(m_bOnLadder)
    {
        if(getPlayerDirection() == PD_BACK)
        {
            if(getPlayerState() == PS_BACKFORWARDRUN)
                setPlayerState(PS_IDLE);
        }
    }
}

void Nilo::onRightBtnPressed()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
    m_bRightBtnPressed = true;
    if(getPlayerDirection() != PD_BACK)
        setPlayerDirection(PD_RIGHT);
    setPlayerState(PS_RUN);
}
void Nilo::onRightBtnReleased()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
    m_bRightBtnPressed = false;
    if(m_bOnLand)
    {
        if(!m_bLeftBtnPressed)
            setPlayerState(PS_IDLE);
        else
            setPlayerDirection(PD_LEFT);
    }
    else
    {
        if(m_bLeftBtnPressed)
            setPlayerDirection(PD_LEFT);
    }
}

void Nilo::onDownBtnPressed()
{
    if(!m_bAcceptInput)
        return;
    m_bDownBtnPressed = true;

    cocos2d::Rect rect = getBoundingBox();
    rect.origin += getPosition() + Vec2(0, -rect.size.height-1);
    UsableItem::USABLE_ITEM_TYPE type = UsableItem::UIT_UNKNOWN;
    bool available = MapMgrs::getInstance()->checkUsableItems(rect, type);
    if(available)
    {
        switch (type) {
            case UsableItem::UIT_LADDER:
            {
                if(getPlayerState() != PS_JUMP && getPlayerState() != PS_SUPERJUMP)
                {
                    m_bOnLadder = true;
                    if(m_PlayerDirection != PD_BACK)
                        setPlayerState(PS_TURNBACK);
                    else
                        setPlayerState(PS_BACKFORWARDRUN);
                }
            }
                break;
            default:
                break;
        }
    }
    else
    {
        if(m_bOnLand)
        {
            if(getPlayerDirection() == PD_BACK)
            {
                setPlayerState(PS_TURNFRONT);
                m_bOnLadder = false;
            }
            else
                setPlayerState(PS_SQUAT);
        }
    }
}
void Nilo::onDownBtnReleased()
{
    if(!m_bAcceptInput)
        return;
    m_bDownBtnPressed = false;
    if(m_bOnLadder)
    {
        if(getPlayerDirection() == PD_BACK)
        {
            if(getPlayerState() == PS_BACKFORWARDRUN)
                setPlayerState(PS_IDLE);
        }
    }
    else
    {
        if(getPlayerState() == PS_SQUAT)
        {
            if(!m_bRightBtnPressed && !m_bLeftBtnPressed)
                setPlayerState(PS_IDLE);
            else
                setPlayerState(PS_RUN);
        }
    }
}

void Nilo::onABtnPressed()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
}
void Nilo::onABtnReleased()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
}

void Nilo::onBBtnPressed()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
    if(getPlayerState() == PS_SUPERJUMP)
        return;
    if(getPlayerState() == PS_JUMP)
        setPlayerState(PS_SUPERJUMP);
    else if(m_bOnLand)
        setPlayerState(PS_JUMP);
}
void Nilo::onBBtnReleased()
{
    if(!m_bAcceptInput)
        return;
    if(m_bOnLadder || getPlayerState() == PS_TURNBACK || getPlayerState() == PS_TURNFRONT)
        return;
}