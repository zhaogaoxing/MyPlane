#include "BaseLayer.h"

USING_NS_CC;

bool  BaseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto bg = TMXTiledMap::create("map/red_bg.tmx");
	this->addChild(bg);

	//�۾�����
	auto glassesSprite = Sprite::createWithSpriteFrameName("setting.glasses.png");
	glassesSprite->setPosition(Vec2(visibleSize.width - glassesSprite->getContentSize().width / 2, 160));
	addChild(glassesSprite);

	//���׾���
	auto handSprite = Sprite::createWithSpriteFrameName("setting.hand.png");
	handSprite->setPosition(Vec2(handSprite->getContentSize().width / 2, 60));
	addChild(handSprite);

	//ok�˵�
	auto okNormal = Sprite::createWithSpriteFrameName("setting.button.ok.png");
	auto okSelected = Sprite::createWithSpriteFrameName("setting.button.ok-on.png");
	auto okMenuItem = MenuItemSprite::create(okNormal, okSelected,
		CC_CALLBACK_1(BaseLayer::menuBackCallback, this));
	auto mu = Menu::create(okMenuItem, NULL);
	mu->setPosition(Vec2(visibleSize.width - mu->getContentSize().width / 2 + 60, 60));
	addChild(mu);

	return true;

}

void BaseLayer::menuBackCallback(Ref* pSender)
{
	Director::getInstance()->popScene();
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY))
	{
		SimpleAudioEngine::getInstance()->playEffect(sound_1);
	}
}

void BaseLayer::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();

	UserDefault * defaults = UserDefault::getInstance();
	if (defaults->getBoolForKey(MUSIC_KEY))
	{
		SimpleAudioEngine::getInstance()->playBackgroundMusic(bg_music_1, true);
	}
}