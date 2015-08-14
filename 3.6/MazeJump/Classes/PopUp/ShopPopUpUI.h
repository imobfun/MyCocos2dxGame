//
//  MainUI.h
//  MazeJump
//
//
//

#ifndef __MazeJump__ShopUI__
#define __MazeJump__ShopUI__

#include "cocos2d.h"
#include "BasePopUpUI.h"
class ShopPopUpUI : public BasePopUpUI
{

public:
    typedef enum {
        SHOP_GOLD = 0,
        SHOP_NORMAL,
    } ShopType;
    virtual void onEnter() override;
    virtual void onExit() override;
    static ShopPopUpUI* create();

    void onBuyGold(Ref* ref);
    void onBuyHeart(Ref* ref);
    void onBuyRemoveAds(Ref* ref);
    void onRestore(Ref* ref);
    
    void onBuyCoin1(Ref* ref);
    void onBuyCoin2(Ref* ref);
    void onBuyCoin3(Ref* ref);
    void onBuyCoin4(Ref* ref);
    void onBuyCoin5(Ref* ref);
    void onBackShop(Ref* ref);
    
    void onProduct(const std::string& productId);
    
    void setShopDisplay(ShopType type);
protected:
    ShopPopUpUI();
    virtual ~ShopPopUpUI();
    virtual bool init();
private:
    cocos2d::Layer* productLayer;
    cocos2d::Layer* goldProductLayer;
    cocos2d::ui::Text* tipTv;
    cocos2d::ui::Text* heartTv;
    cocos2d::ui::Text* goldTv;
    ShopType m_shopType;
};

#endif /* defined(__MazeJump__ShopUI__) */