#ifndef MSG_GAME_TEST_TESTGAMESTATE_HPP
#define MSG_GAME_TEST_TESTGAMESTATE_HPP

#include "State.hpp"


#include <cmath>
#include <sstream>

#include "imgui.h"
#include "imgui-SFML.h"

#include "SFML/Audio/Listener.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include "Components/AnimationComponent.hpp"
#include "Components/CollisionComponent.hpp"
#include "Components/HealthComponent.hpp"

#include "Entities/EntityFactory.hpp"

#include "Systems/AnimationSystem.hpp"

#include "Tilemap/TileMapRenderer.hpp"
#include "Tilemap/TileMapSerializer.hpp"

#include "CharacterRenderer.hpp"
#include "Console.hpp"
#include "GameEngine.hpp"
#include "Global.hpp"
#include "IMouseEventListener.hpp"
#include "Player.hpp"
#include "TextureManager.hpp"
#include "TilemapEditor.hpp"


class TestGameState : public State
{
public:
    bool init() final override;

    void onResize(int width, int height) final override;

    void onMouseButton(int x, int y, int button, bool pressed) final override;

    void onMouseWheelMoved(float delta) final override;

    void onKey(int keyCode, bool control, bool alt, bool shift, bool system, bool pressed) final override;

    void update() final override;

    void render() final override;

    void cleanup() final override;

    void imguiUpdate() final override;

public:
    sf::View camera;
    std::vector<IMouseEventListener*> mouseListeners;
    Console console;

    enum Movement {UP, DOWN, LEFT, RIGHT};
    Player player;
    bool torchLit = false;
    Entity torch2;
    bool lightControl = false;
    AnimationSystem animationSystem;
    sf::Clock deltaClock;
    std::string action = "Idle";
    TileMap map;
    const int CanSwim = false;
    sf::RectangleShape rect;
    sf::Sprite torch;
    Entity trans;
    Entity character;
    Entity chest;
    sf::Clock frameTime;
    sf::Clock torchClock;
    float seconds = -3.f;
    Tile* selectedTile = nullptr;
    TileMapRenderer mapRenderer;
    TileMapSerializer serializer;
    CharacterRenderer characterRenderer;
    sf::RenderTexture lightmap;
    sf::Sprite lightmapSprite;
    sf::RectangleShape blackbox;
    sf::Sprite light;
    TilemapEditor editor;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    bool m_interact;
    bool m_sprint;
}; // TestGameState

#endif // MSG_GAME_TEST_TESTGAMESTATE_HPP
