CutsceneTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CutsceneTown_OnFrame
	.byte 0

CutsceneTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 11, CutsceneTown_Event
	.2byte 0

CutsceneTown_Event::
	lockall
	special SpawnCameraObject
	delay 100
	playbgm MUS_DP_CANALAVE_DAY, FALSE
	applymovement LOCALID_CAMERA, MythTown_Movement_PositionCameraToFirstShot
	waitmovement 0
	delay 80
	applymovement LOCALID_TOWNMYTH_WESTCELEBI, MythTown_Movement_WestCelebi
	fadescreen FADE_FROM_BLACK
	delay 80
	message Myth_Text_WhoRestoredLife
	waitmessage
	applymovement LOCALID_TOWNMYTH_BUNNELBYN, TownMyth_Movement_BunnelbyN
	delay 20
	applymovement LOCALID_TOWNMYTH_BUNNELBYS, TownMyth_Movement_BunnelbyS
	delay 70
	applymovement LOCALID_TOWNMYTH_WESTWOMAN, MythTown_Movement_ManWomanEnterWestScene
	delay 5
	applymovement LOCALID_TOWNMYTH_WESTMAN, MythTown_Movement_ManWomanEnterWestScene
	delay 110
	closemessage
	delay 30
	playse SE_PIN
	applymovement LOCALID_TOWNMYTH_WESTMAN, MythTown_Movement_ManLoveWoman
	applymovement LOCALID_TOWNMYTH_WESTWOMAN, MythTown_Movement_WomanLoveMan
	delay 150
	fadescreen FADE_TO_BLACK
	delay 40
	applymovement LOCALID_CAMERA, MythTown_Movement_PositionCameraToSecondShot
	waitmovement 0
	applymovement LOCALID_TOWNMYTH_TAUROS, MythTown_Movement_DrinkWater
	applymovement LOCALID_TOWNMYTH_MUDSDALE, MythTown_Movement_DrinkWater
	applymovement LOCALID_TOWNMYTH_CARROTMAN, MythTown_Movement_CarrotMan
	applymovement LOCALID_CAMERA, MythTown_Movement_CameraPanOverFarms
	fadescreen FADE_FROM_BLACK
	message Myth_Text_Landorus
	waitmessage
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	applymovement LOCALID_TOWNMYTH_CABBAGEMAN, MythTown_Movement_CabbageMan
	applymovement LOCALID_TOWNMYTH_LANDORUS, MythTown_Movement_Landorus
	delay 200
	closemessage
	fadescreen FADE_TO_BLACK
	delay 80
	applymovement LOCALID_CAMERA, MythTown_Movement_PositionCameraToThirdShot
	waitmovement 0
	applymovement LOCALID_TOWN_NORTHCELEBI, MythTown_Movement_WestCelebi
	fadescreen FADE_FROM_BLACK
	message Myth_Text_Celebi
	waitmessage
	delay 100
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	applymovement LOCALID_TOWNMYTH_KECLEON, Myth_Movement_KecleonAppears
	delay 60
	playse SE_PIN
	applymovement LOCALID_TOWNMYTH_NORTHWOMAN, Common_Movement_FaceUpExclamationMark
	delay 80
	closemessage
	applymovement LOCALID_TOWNMYTH_KECLEON, Myth_Movement_KecleonEscapeToForest
	waitmovement 0
	delay 100
	fadescreen FADE_TO_BLACK
	delay 80
	message Myth_Text_NowLandorus
	waitmessage
	delay 180
	message Myth_Text_NowCelebi
	waitmessage
	fadenewbgm MUS_NONE
	delay 180
	playbgm MUS_NONE, TRUE
	closemessage
	delay 80
	clearflag FLAG_SYS_SPAWN_INVISIBLE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	warpsilent MAP_SHRINE_OF_PROSPERITY_PAST, 12, 10
	end

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

TownMyth_Movement_BunnelbyN:
	jump_right
	delay_16
	delay_8
	jump_left
	delay_16
	delay_16
	jump_up
	jump_up
	jump_up
	jump_up
	jump_up
	step_end

TownMyth_Movement_BunnelbyS:
	jump_right
	delay_4
	jump_right
	delay_8
	jump_up
	delay_16
	delay_16
	delay_8
	jump_right
	jump_down
	jump_down
	jump_down
	jump_down
	jump_down
	step_end
	
MythTown_Movement_WestCelebi:
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	step_end

MythTown_Movement_DrinkWater:
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

MythTown_Movement_Landorus:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_right
	walk_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_right
	step_end

@9 23 to 10 24
MythTown_Movement_PositionCameraToFirstShot:
	walk_faster_down
	walk_faster_right
	step_end

@10 24 to 21 29
MythTown_Movement_PositionCameraToSecondShot:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

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

@21 29 to 44 29
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

@44 29 to 38 18
MythTown_Movement_PositionCameraToThirdShot:
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
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
