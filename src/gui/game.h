//
// Created by Sebastian on 25.10.26.
//

#ifndef SRC_GUI_GAME_H
#define SRC_GUI_GAME_H

#include <contracts/app/view.h>
#include <contracts/gui/keyevent.h>
#include <contracts/gui/gamecontroller.h>
#include <contracts/gui/worldstate.h>
#include <contracts/gui/playerstate.h>
#include <contracts/gui/texturehandler.h>

#include <common/map.h>
#include <common/rgb.h>

#include <unordered_map>
#include <vector>

namespace gui
{
class Game : public app::View
{
public:
	Game(SDL_Renderer&, KeyEvent&, GameController&, WorldState&, PlayerState&, TextureHandler&);

	void render() override;
	void entry() override;
	void exit() override;
	[[nodiscard]] common::eView type() const override;
	app::ChangeViewSignal& change() override;

private:
	struct sDisplayResolution
	{
		int w;
		int h;
	};

	struct sWindowSize
	{
		int w;
		int h;
	};

	static constexpr size_t kReferenceWidth{1920U};
	static constexpr size_t kReferenceHeight{1080U};
	static constexpr size_t kReferenceBlocksPerWidth{48U};
	static constexpr size_t kReferenceBlocksPerHeight{27U};
	static constexpr size_t kReferenceBlockSize{40U};

	void onKeyDown(SDL_Keycode key);

	void drawMap();
	void drawBlock(common::eBlock, float, float, float);
	void createBlockTexture(common::eBlock);
	sDisplayResolution displayResoultion(bool&) const;
	sWindowSize windowSize() const;

	app::ChangeViewSignal m_change{};
	boost::signals2::scoped_connection m_keyConnection{};
	std::unordered_map<common::eBlock, SDL_Texture*> blockTextures{};

	SDL_Renderer& m_renderer;
	KeyEvent& m_keyEvent;
	GameController& m_gameController;
	WorldState& m_worldState;
	PlayerState& m_playerState;
	TextureHandler& m_textureHandler;
};
}

#endif //SRC_GUI_GAME_H
