// Copyright (c) 2013- PPSSPP Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official git repository and contact information can be found at
// https://github.com/hrydgard/ppsspp and http://www.ppsspp.org/.

#pragma once

#include "base/functional.h"
#include "ui/ui_screen.h"
#include "ui/viewgroup.h"
#include "UI/MiscScreens.h"

// Game screen: Allows you to start a game, delete saves, delete the game,
// set game specific settings, etc.
// Uses GameInfoCache heavily to implement the functionality.

class MainScreen : public UIScreenWithBackground {
public:
	MainScreen();
	~MainScreen();

	virtual bool isTopLevel() const { return true; }

	// Horrible hack to show the demos & homebrew tab after having installed a game from a zip file.
	static bool showHomebrewTab;

protected:
	virtual void CreateViews();
	virtual void DrawBackground(UIContext &dc);
	virtual void update(InputState &input);
	virtual void sendMessage(const char *message, const char *value);
	virtual void dialogFinished(const Screen *dialog, DialogResult result);

private:
	bool DrawBackgroundFor(UIContext &dc, const std::string &gamePath, float progress);

	UI::EventReturn OnGameSelected(UI::EventParams &e);
	UI::EventReturn OnGameSelectedInstant(UI::EventParams &e);
	UI::EventReturn OnGameHighlight(UI::EventParams &e);
	// Event handlers
	UI::EventReturn OnLoadFile(UI::EventParams &e);
	UI::EventReturn OnGameSettings(UI::EventParams &e);
	UI::EventReturn OnRecentChange(UI::EventParams &e);
	UI::EventReturn OnCredits(UI::EventParams &e);
	UI::EventReturn OnSupport(UI::EventParams &e);
	UI::EventReturn OnPPSSPPOrg(UI::EventParams &e);
	UI::EventReturn OnForums(UI::EventParams &e);
	UI::EventReturn OnExit(UI::EventParams &e);
	UI::EventReturn OnDownloadUpgrade(UI::EventParams &e);
	UI::EventReturn OnDismissUpgrade(UI::EventParams &e);
	UI::EventReturn OnHomebrewStore(UI::EventParams &e);

	UI::LinearLayout *upgradeBar_;
	UI::TabHolder *tabHolder_;

	std::string highlightedGamePath_;
	std::string prevHighlightedGamePath_;
	float highlightProgress_;
	float prevHighlightProgress_;
	bool backFromStore_;
	bool lockBackgroundAudio_;
	bool lastVertical_;

	bool UseVerticalLayout() const;
};

class UmdReplaceScreen : public UIDialogScreenWithBackground {
public:
	UmdReplaceScreen() {}

protected:
	virtual void CreateViews();
	virtual void update(InputState &input);
	//virtual void sendMessage(const char *message, const char *value);

private:
	UI::EventReturn OnGameSelected(UI::EventParams &e);
	UI::EventReturn OnGameSelectedInstant(UI::EventParams &e);

	UI::EventReturn OnCancel(UI::EventParams &e);
	UI::EventReturn OnGameSettings(UI::EventParams &e);
};
