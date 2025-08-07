CutsceneMyth_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneMyth_Event
	.byte 0

CutsceneMyth_Event::
	lockall
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 20
	special TeleportCamera

@Pan over an empty forest
Myth_Text_LongAgo:
	.string "Long ago, Porta Bella was nothing\n"
	.string "more than a turbulent wasteland on\l"
	.string "a stormy ocean bay.$"

@Pan down to Tornadus
Myth_Text_SpiritOfWind:
	.string "The Spirit of Wind claimed\n"
	.string "the territority of the forest…$"

@Pan up to Thundurus
Myth_Text_SpiritOfStorms:
	.string "…While the Spirit of Lightning claimed\n"
	.string "dominion over the bay.$"

@Genies at each others' throats
Myth_Text_FightEndlessly:
	.string "They were locked in an endless battle\n"
	.string "for the right to rule the land.$"

@Pan over humans and Pokemon
Myth_Text_HumansPokemon:
	.string "Humans hunkered down in caves.\p"
	.string "Pokémon feared being the target of\n"
	.string "a spirit's wrath.$"

@Landorus enters shot of genies fighting, beats them up.
Myth_Text_AsIfFromThinAir:
	.string "Then, as if from the heavens,\n"
	.string "Landorus came down, and quelled the\l"
	.string "two fighting spirits.$"

Myth_Text_WithTheSpiritsQuelled:
	.string "With the spirits pacified, so too\n"
	.string "appeared Celebi, who restored to life\l"
	.string "flora which had gone extinct in\l"
	.string "decades past.$"
