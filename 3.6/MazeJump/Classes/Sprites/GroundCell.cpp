//
//  GroundCell.cpp
//  MazeJump
//
//  Created by wang haibo on 15/6/24.
//
//

#include "GroundCell.h"
#include "OutlineEffect3D.h"
USING_NS_CC;

GroundCell* GroundCell::create()
{
    auto cell = new (std::nothrow) GroundCell();
    if (cell && cell->initWithFile("platform.obj"))
    {
        cell->setTexture("IndexColor.png");
        cell->_contentSize = cell->getBoundingBox().size;
        cell->m_fRadius = cell->_contentSize.width*0.5f;
        
        OutlineEffect3D* outline = OutlineEffect3D::create();
        outline->setOutlineColor(Vec3(0.3f, 0.3f, 0.3f));
        outline->setOutlineWidth(0.03f);
        cell->addEffect(outline, 1);
        
        cell->autorelease();
        return cell;
    }
    CC_SAFE_DELETE(cell);
    return nullptr;
}
GroundCell::GroundCell()
{
}