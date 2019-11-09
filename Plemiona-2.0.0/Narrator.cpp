#include "Narrator.h"
#include "UI.h"

void Narrator::AddInfo(std::string str)
{

	if (info[0] == " ")info.erase(info.begin());
	else pages++;
	info.push_back(str);
	read.push_back(false);

	if (Game::current_narrator_page == 0)UI::strings::narratorText.SetText(str);
	if (read_count < read.size() - 1)UI::Lights::narrator_unread.active = true;
	else UI::Lights::narrator_unread.active = false;

}