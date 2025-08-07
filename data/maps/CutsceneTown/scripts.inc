CutsceneTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneTown_OnFrame
	.byte 0

CutsceneTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 9, CutsceneTown_Event
	.2byte 0

CutsceneTown_Event::
	lockall
	special SpawnCameraObject
	setvar VAR_0x8004, 10
	setvar VAR_0x8005, 24
	special TeleportCamera
	fadescreen FADE_FROM_BLACK
	delay 40
	message Myth_Text_WhoRestoredLife
	applymovement LOCALID_TOWNMYTH_WESTWOMAN, MythTown_Movement_ManWomanEnterWestScene
	delay 5
	applymovement LOCALID_TOWNMYTH_WESTMAN, MythTown_Movement_ManWomanEnterWestScene
	delay 80
	closemessage
	delay 20
	applymovement LOCALID_TOWNMYTH_WESTMAN, MythTown_Movement_ManLoveWoman
	applymovement LOCALID_TOWNMYTH_WESTWOMAN, MythTown_Movement_WomanLoveMan
	delay 50
	fadescreen FADE_TO_BLACK
	delay 40
	setvar VAR_0x8004, 21
	setvar VAR_0x8005, 29
	special TeleportCamera
	applymovement LOCALID_CAMERA, MythTown_Movement_CameraPanOverFarms
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_TOWNMYTH_CARROTMAN, MythTown_Movement_CarrotMan
	applymovement LOCALID_TOWNMYTH_CABBAGEMAN, MythTown_Movement_CabbageMan
	message Myth_Text_Landorus
	waitmessage
	delay 80
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 10
	special TeleportCamera
	message Myth_Text_Celebi
	fadescreen FADE_FROM_BLACK
	delay 40
	applymovement LOCALID_TOWNMYTH_KECLEON, Myth_Movement_KecleonAppears
	delay 60
	closemessage
	applymovement LOCALID_TOWNMYTH_NORTHWOMAN, Common_Movement_FaceUpExclamationMark
	delay 48
	applymovement LOCALID_TOWNMYTH_KECLEON, Myth_Movement_KecleonEscapeToForest
	waitmovement 0
	fadescreen FADE_TO_BLACK
	delay 80
	message Myth_Text_NowLandorus
	waitmessage
	delay 80
	message Myth_Text_NowCelebi
	waitmessage
	delay 80
	closemessage
	delay 80
	clearflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warpsilent MAP_SHRINE_OF_PROSPERITY_PAST, 12, 10
	end

MythTown_Movement_ManWomanEnterWestScene:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MythTown_Movement_ManLoveWoman:
	face_up
	emote_heart
	step_end

MythTown_Movement_WomanLoveMan:
	face_down
	emote_heart
	step_end

MythTown_Movement_CameraPanOverFarms:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MythTown_Movement_CarrotMan:
	delay_16
	delay_16
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

MythTown_Movement_CabbageMan:
	face_down
	delay_4
	face_up
	delay_4
	face_down
	delay_4
	jump_in_place_right
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	delay_4
	face_down
	delay_4
	face_up
	delay_4
	face_down
	delay_16
	delay_8
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Myth_Movement_KecleonAppears:
	face_down
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end

Myth_Movement_KecleonEscapeToForest:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

Myth_Text_WhoRestoredLife:
	.string "…Who restored to life flora which\n"
	.string "had gone extinct in decades past.$"

Myth_Text_Landorus:
	.string "Landorus fertilized the land to\n"
	.string "bring about abundance in the region,$"

Myth_Text_Celebi:
	.string "and Celebi protected the land from\n"
	.string "any outside intruder.$"

 Myth_Text_GivenTheTitles:
	.string "Celebi was deemed the Spirit of Peace,\n"
	.string "and Landorus the Spirit of Prosperity.$"

Myth_Text_NowLandorus:
	.string "To this day, Landorus keeps Tornadus\n"
	.string "and Thundurus from rampaging again,$"

Myth_Text_NowCelebi:
	.string "and Celebi protects the peaceful lives\n"
	.string "of the citizens of Porta Bella.$"
