#pragma once
class OptionScene
{
public:
	OptionScene();
	~OptionScene();

	void DrawFrame();
	void OptionText();
	

	struct OptionDate
	{
     int Option_posX;
	int Option_posY;
	char OptionItemName[100];
	};
	OptionDate option_date[20]
	{
		{100,200,"Bgm"},
		{100,300,"Degree of difficulty"},
		{100,400,"Voice"}

	};
	






private:

};



