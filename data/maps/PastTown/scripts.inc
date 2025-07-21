PastTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PastTown_OnFrame
	.byte 0

PastTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 5, PastTown_EventScript_LookerEnters
	.2byte 0

PastTown_EventScript_LookerEnters::
	lockall
	msgbox PastTown_Text_LookerWhatIsThis, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 40
	playse SE_EFFECTIVE
	delay 10
	msgbox PastTown_Text_LookerYowch, MSGBOX_DEFAULT
	delay 30
	closemessage
	delay 30
	fadescreen FADE_FROM_BLACK
	delay 60
	msgbox PastTown_Text_LookerImNotDreaming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, PastTown_Movement_LookerLookAround
	waitmovement 0
	msgbox PastTown_Text_LookerOutOfTheWoods, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CUTSCENE_STATE, 6
	releaseall
	end

PastTown_EventScript_LookerPassOut::
	lockall
	msgbox PastTown_Text_LookerUrgh, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	warpsilent MAP_PAST_TOWN_HALL, 2, 2
	delay 48
	end

PastTown_Movement_LookerLookAround:
	walk_down
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

PastTown_Text_LookerUrgh:
	.string "Urrrrggghhh…$"

PastTown_Text_LookerImNotDreaming:
	.string "Alright, I am definitely\n"
	.string "not dreaming!$"

PastTown_Text_LookerOutOfTheWoods:
	.string "Not sure where this is, but\n"
	.string "no matter.\p"
	.string "I need to get to a Pokémon Center\n"
	.string "and treat this pain pronto…$"

PastTown_Text_LookerWhatIsThis:
	.string "What…?\p"
	.string "Where am I…?\p"
	.string "I'm positive the city is supposed\n"
	.string "to be right here.\p"
	.string "I'm not dreaming, am I?$"

PastTown_Text_LookerYowch:
	.string "YOWCH!!!$"