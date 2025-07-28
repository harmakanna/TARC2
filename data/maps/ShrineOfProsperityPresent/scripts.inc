ShrineOfProsperityPresent_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfProsperityPresent_EventScript_OnTransition
	.byte 0

ShrineOfProsperityPresent_EventScript_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_eq VAR_QUEUE_GENIE_FIGHT, 3, ShrineOfProsperityPresent_EventScript_SetTornadusFaceDown
	end

ShrineOfProsperityPresent_EventScript_SetTornadusFaceDown::
	setobjectmovementtype LOCALID_SHRINE_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	return

ShrineOfProsperityPresent_EventScript_StartGenieFight::
	lockall
	faceplayer
	clearflag FLAG_HIDE_SHRINE_THUNDURUS
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	waitmoncry
	setobjectxyperm LOCALID_SHRINE_THUNDURUS, 12, 16
	addobject LOCALID_SHRINE_THUNDURUS
	delay 40
	call_if_eq VAR_FACING, DIR_NORTH, ShrineOfProsperityPresent_EventScript_ThundurusRushN
	call_if_eq VAR_FACING, DIR_EAST, ShrineOfProsperityPresent_EventScript_ThundurusRushE
	call_if_eq VAR_FACING, DIR_WEST, ShrineOfProsperityPresent_EventScript_ThundurusRushW
	playmoncry SPECIES_THUNDURUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_TORNADUS, 5, ITEM_NONE, SPECIES_THUNDURUS, 5, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattleDouble
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ShrineOfProsperityPresent_EventScript_DefeatedGenies
	setflag FLAG_HIDE_SHRINE_THUNDURUS
	releaseall
	end

ShrineOfProsperityPresent_EventScript_ThundurusRushN::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushN
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_ThundurusRushE::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushE
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_ThundurusRushW::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushW
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_DefeatedGenies::
 	delay 40
	msgbox ShrineOfProsperityPresent_Text_TornadusThundurusDefeat, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, ShrineOfProsperityPresent_EventScript_GeniesEscapeN
	call_if_eq VAR_FACING, DIR_EAST, ShrineOfProsperityPresent_EventScript_GeniesEscapeE
	call_if_eq VAR_FACING, DIR_WEST, ShrineOfProsperityPresent_EventScript_GeniesEscapeW
	removeobject LOCALID_SHRINE_TORNADUS
	removeobject LOCALID_SHRINE_THUNDURUS
	delay 40
	msgbox ShrineOfProsperityPresent_Text_LookerReportBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SHADE
	doweather
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	delay 100
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	msgbox ShrineOfProsperityPresent_Text_LookerTheWeather, MSGBOX_DEFAULT
	closemessage
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INVESTIGATE_PROSPERITY, SUB_QUEST_DEFEAT_GENIES
	questmenu QUEST_MENU_SET_REWARD QUEST_INVESTIGATE_PROSPERITY
	clearflag FLAG_HIDE_OUTSIDE_NPCS
	setflag FLAG_DEFEATED_SHRINE_GENIES
	setflag FLAG_HIDE_INSIDE_OUTSIDE_NPCS
	setvar VAR_QUEUE_GENIE_FIGHT, 4
	releaseall
	end

ShrineOfProsperityPresent_EventScript_GeniesEscapeN::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_LookerWatchGenies
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusEscapeN
	applymovement LOCALID_SHRINE_TORNADUS, ShrineOfProsperityPresent_Movement_TornadusEscapeN
	waitmovement 0
	return

ShrineOfProsperityPresent_EventScript_GeniesEscapeE::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_LookerWatchGeniesShort
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusEscapeE
	applymovement LOCALID_SHRINE_TORNADUS, ShrineOfProsperityPresent_Movement_TornadusEscapeE
	waitmovement 0
	return

ShrineOfProsperityPresent_EventScript_GeniesEscapeW::
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_LookerWatchGeniesShort
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusEscapeW
	applymovement LOCALID_SHRINE_TORNADUS, ShrineOfProsperityPresent_Movement_TornadusEscapeW
	waitmovement 0
	return

ShrineOfProsperityPresent_Movement_LookerWatchGenies:
	delay_16
	face_down
	step_end

ShrineOfProsperityPresent_Movement_LookerWatchGeniesShort:
	delay_8
	face_down
	step_end

ShrineOfProsperityPresent_Movement_ThundurusEscapeN:
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

ShrineOfProsperityPresent_Movement_TornadusEscapeN:
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

ShrineOfProsperityPresent_Movement_ThundurusEscapeE:
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

ShrineOfProsperityPresent_Movement_TornadusEscapeE:
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end


ShrineOfProsperityPresent_Movement_ThundurusEscapeW:
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

ShrineOfProsperityPresent_Movement_TornadusEscapeW:
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end


ShrineOfProsperityPresent_EventScript_GeniePan::
	lockall
	special SpawnCameraObject
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 11, ShrineOfProsperityPresent_EventScript_PanCameraL
	call_if_eq VAR_TEMP_1, 12, ShrineOfProsperityPresent_EventScript_PanCameraM
	call_if_eq VAR_TEMP_1, 13, ShrineOfProsperityPresent_EventScript_PanCameraR
	setobjectmovementtype LOCALID_SHRINE_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	delay 48
	msgbox ShrineOfProsperityPresent_Text_LookerAreThosePokeballs, MSGBOX_DEFAULT
	closemessage
	delay 40
	special RemoveCameraObject
	setvar VAR_QUEUE_GENIE_FIGHT, 3
	releaseall
	end
	
ShrineOfProsperityPresent_EventScript_PanCameraL::
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraUpL
    waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_SHRINE_TORNADUS, Common_Movement_FaceDownExclamationMark
	delay 48
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraDownL
	waitmovement 0
	delay 60
	return

ShrineOfProsperityPresent_EventScript_PanCameraM::
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraUpM
    waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_SHRINE_TORNADUS, Common_Movement_FaceDownExclamationMark
	delay 48
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraDownM
	waitmovement 0
	delay 60
	return

ShrineOfProsperityPresent_EventScript_PanCameraR::
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraUpR
    waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_SHRINE_TORNADUS, Common_Movement_FaceDownExclamationMark
	delay 48
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraDownR
	waitmovement 0
	delay 60
	return

ShrineOfProsperityPresent_Movement_ThundurusRushN:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	face_up
	step_end

ShrineOfProsperityPresent_Movement_ThundurusRushE:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	face_up
	step_end
	
ShrineOfProsperityPresent_Movement_ThundurusRushW:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_left
	face_up
	step_end

ShrineOfProsperityPresent_Movement_PanCameraUpL:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

ShrineOfProsperityPresent_Movement_PanCameraUpM:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ShrineOfProsperityPresent_Movement_PanCameraUpR:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ShrineOfProsperityPresent_Movement_PanCameraDownL:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

ShrineOfProsperityPresent_Movement_PanCameraDownM:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperityPresent_Movement_PanCameraDownR:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

ShrineOfProsperityPresent_Text_Tornadus:
	.string "Graaaaargh!!!$"

ShrineOfProsperityPresent_Text_TornadusThundurusDefeat:
	.string "Tornadus: Grrrrrr…\p"
	.string "Thundurus: Graaaah…$"

ShrineOfProsperityPresent_Text_LookerAreThosePokeballs:
	.string "Huh?\n"
	.string "Are those…\p"
	.string "Pokéballs on the ground?$"

ShrineOfProsperityPresent_Text_LookerReportBack:
	.string "Hmm…\p"
	.string "The rangers will be sure to find\n"
	.string "this interesting…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

ShrineOfProsperityPresent_Text_LookerTheWeather:
	.string "The weather…\n"
	.string "It's clearing up!$"
