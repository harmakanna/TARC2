ShrineOfProsperityPresent_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineOfProsperityPresent_EventScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ShrineOfProsperityPresent_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShrineOfProsperityPresent_OnFrame
	.byte 0

ShrineOfProsperityPresent_EventScript_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_eq VAR_QUEUE_GENIE_FIGHT, 3, ShrineOfProsperityPresent_EventScript_SetTornadusFaceDown
	call_if_eq VAR_CUTSCENE_STATE, 14, ShrineOfProsperityPresent_EventScript_SetResolution
	end

ShrineOfProsperityPresent_EventScript_SetTornadusFaceDown::
	setflag FLAG_HIDE_SHRINE_THUNDURUS
	setobjectmovementtype LOCALID_SHRINE_TORNADUS, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	return

ShrineOfProsperityPresent_EventScript_SetResolution::
	call_if_eq VAR_CHOOSE_CULPRIT, 0, ShrineOfProsperityPresent_EventScript_ControlBlue
	call_if_eq VAR_CHOOSE_CULPRIT, 1, ShrineOfProsperityPresent_EventScript_ControlMay
	call_if_eq VAR_CHOOSE_CULPRIT, 2, ShrineOfProsperityPresent_EventScript_ControlLeaf
	call_if_eq VAR_CHOOSE_CULPRIT, 3, ShrineOfProsperityPresent_EventScript_ControlAceTrainer
	call_if_eq VAR_CHOOSE_CULPRIT, 4, ShrineOfProsperityPresent_EventScript_ControlYoungster
	return

ShrineOfProsperityPresent_EventScript_ControlBlue::
	setvar VAR_TEMP_1, LOCALID_SHRINE_BLUE
	return
	
ShrineOfProsperityPresent_EventScript_ControlMay::
	setvar VAR_TEMP_1, LOCALID_SHRINE_MAY
	return
	
ShrineOfProsperityPresent_EventScript_ControlLeaf::
	setvar VAR_TEMP_1, LOCALID_SHRINE_LEAF
	return
	
ShrineOfProsperityPresent_EventScript_ControlAceTrainer::
	setvar VAR_TEMP_1, LOCALID_SHRINE_ACE_TRAINER
	return
	
ShrineOfProsperityPresent_EventScript_ControlYoungster::
	setvar VAR_TEMP_1, LOCALID_SHRINE_YOUNGSTER
	return
	
ShrineOfProsperityPresent_OnResume:
	special HealPlayerParty
	end
	
ShrineOfProsperityPresent_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 14, ShrineOfProsperityPresent_EventScript_Resolution
	.2byte 0

ShrineOfProsperityPresent_EventScript_Resolution::
	lockall
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ShrineOfProsperityPresent_Movement_PanCameraToResolutionPosition
	waitmovement 0
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_LookerWalkUpResolution
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_CulpritWalkUpResolution
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_AnabelWalkUpResolution
	fadescreen FADE_FROM_BLACK
	waitmovement LOCALID_PROSPERITY_PRESENT_ANABEL
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement VAR_TEMP_1, Common_Movement_FaceRight
	speak LOCALID_PROSPERITY_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfProsperityPresent_Text_AnabelItsTime
	call_if_eq VAR_CHOOSE_CULPRIT, 0, ShrineOfProsperityPresent_EventScript_BlueYes
	call_if_eq VAR_CHOOSE_CULPRIT, 1, ShrineOfProsperityPresent_EventScript_MayYes
	call_if_eq VAR_CHOOSE_CULPRIT, 2, ShrineOfProsperityPresent_EventScript_LeafYes
	call_if_eq VAR_CHOOSE_CULPRIT, 3, ShrineOfProsperityPresent_EventScript_AceTrainerYes
	call_if_eq VAR_CHOOSE_CULPRIT, 4, ShrineOfProsperityPresent_EventScript_YoungsterYes	
	speak LOCALID_PROSPERITY_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfProsperityPresent_Text_AnabelLandorusGoFree
	closemessage
	applymovement VAR_TEMP_1, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, Common_Movement_FaceUp
	waitmovement VAR_TEMP_1
	delay 20
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	waitse
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_LANDORUS
	addobject LOCALID_PROSPERITY_PRESENT_LANDORUS
	waitmoncry
	delay 10
	fadescreen FADE_FROM_WHITE
	delay 40
	playfanfare MUS_EVOLVED
	message ShrineOfProsperityPresent_Text_LandorusWasSetFree
	waitmessage
	waitfanfare
	closemessage
	delay 80
	applymovement VAR_TEMP_1, Common_Movement_WalkLeft
	waitmovement 0
	call_if_eq VAR_CHOOSE_CULPRIT, 0, ShrineOfProsperityPresent_EventScript_BlueBye
	call_if_eq VAR_CHOOSE_CULPRIT, 1, ShrineOfProsperityPresent_EventScript_MayBye
	call_if_eq VAR_CHOOSE_CULPRIT, 2, ShrineOfProsperityPresent_EventScript_LeafBye
	call_if_eq VAR_CHOOSE_CULPRIT, 3, ShrineOfProsperityPresent_EventScript_AceTrainerBye
	call_if_eq VAR_CHOOSE_CULPRIT, 4, ShrineOfProsperityPresent_EventScript_YoungsterBye
	delay 60
	applymovement LOCALID_PROSPERITY_PRESENT_LANDORUS, ShrineOfProsperityPresent_Movement_LandorusWalkToLooker
	playse SE_PIN
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, Common_Movement_FaceLeftExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceUpExclamationMark
	waitmovement 0
	delay 50
	playmoncry SPECIES_LANDORUS, CRY_MODE_NORMAL
	message ShrineOfProsperityPresent_Text_Landorus
	waitmessage
	waitmoncry
	msgbox ShrineOfProsperityPresent_Text_LandorusLook, MSGBOX_DEFAULT
	closemessage
	delay 40
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_PROSPERITY_PRESENT_LANDORUS, ShrineOfProsperityPresent_Movement_LandorusFlyOff
	waitmovement 0
	removeobject LOCALID_PROSPERITY_PRESENT_LANDORUS
	delay 40
	call_if_set FLAG_SYS_WEATHER_CTRL, ShrineOfProsperityPresent_EventScript_ResolutionStopWeather
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, Common_Movement_WalkLeft
	waitmovement 0
	speak LOCALID_PROSPERITY_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfProsperityPresent_Text_AnabelThatsThat
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, ShrineOfProsperityPresent_Text_LookerIndeed
	speak LOCALID_PROSPERITY_PRESENT_ANABEL, DIR_WEST, Name_Anabel, ShrineOfProsperityPresent_Text_AnabelSoundsLikeAPlan
	closemessage
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_AnabelLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_LookerLeave
	delay 80
	fadescreen FADE_TO_BLACK
	waitmovement LOCALID_PLAYER
	delay 120
	message Epilogue_Text_AFewDaysLater
	waitmessage
	delay 100
	closemessage
	clearflag FLAG_SYS_WEATHER_CTRL
	clearflag FLAG_HIDE_PORT_ANABEL
	setflag FLAG_HIDE_PORT_BLUE
	setflag FLAG_HIDE_CITY_THUNDURUS
	setflag FLAG_HIDE_CITY_TORNADUS
	special RemoveCameraObject
	warpsilent MAP_PRESENT_TOWN_PORT, 14, 10
	waitstate
	releaseall
	end

ShrineOfProsperityPresent_EventScript_BlueYes::
	speak VAR_TEMP_1, DIR_EAST, Name_Blue, ShrineOfProsperityPresent_Text_BlueYes
	return
	
ShrineOfProsperityPresent_EventScript_MayYes::
	speak VAR_TEMP_1, DIR_EAST, Name_May, ShrineOfProsperityPresent_Text_MayYes
	return
	
ShrineOfProsperityPresent_EventScript_LeafYes::
	speak VAR_TEMP_1, DIR_EAST, Name_Leaf, ShrineOfProsperityPresent_Text_Leaf
	return
	
ShrineOfProsperityPresent_EventScript_AceTrainerYes::
	speak VAR_TEMP_1, DIR_EAST, Name_Ace_Trainer, ShrineOfProsperityPresent_Text_AceTrainerYes
	return
	
ShrineOfProsperityPresent_EventScript_YoungsterYes::
	speak VAR_TEMP_1, DIR_EAST, Name_Youngster, ShrineOfProsperityPresent_Text_YoungsterYes
	return
	
ShrineOfProsperityPresent_EventScript_BlueBye::
	speak VAR_TEMP_1, DIR_SOUTH, Name_Blue, ShrineOfProsperityPresent_Text_BlueBye
	closemessage
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_CulpritLeave
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	waitmovement VAR_TEMP_1
	return
	
ShrineOfProsperityPresent_EventScript_MayBye::
	speak VAR_TEMP_1, DIR_SOUTH, Name_May, ShrineOfProsperityPresent_Text_MayBye
	closemessage
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_CulpritLeave
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	waitmovement VAR_TEMP_1
	return
	
ShrineOfProsperityPresent_EventScript_LeafBye::
	speak VAR_TEMP_1, DIR_SOUTH, Name_Leaf, ShrineOfProsperityPresent_Text_LeafBye
	closemessage
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_CulpritLeave
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	waitmovement VAR_TEMP_1
	return
	
ShrineOfProsperityPresent_EventScript_AceTrainerBye::
	speak VAR_TEMP_1, DIR_SOUTH, Name_Ace_Trainer, ShrineOfProsperityPresent_Text_AceTrainerBye
	closemessage
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_CulpritLeave
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_WatchCulpritLeave
	waitmovement VAR_TEMP_1
	return
	
ShrineOfProsperityPresent_EventScript_YoungsterBye::
	speak VAR_TEMP_1, DIR_SOUTH, Name_Youngster, ShrineOfProsperityPresent_Text_YoungsterBye
	closemessage
	applymovement VAR_TEMP_1, ShrineOfProsperityPresent_Movement_YoungsterLeave
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, ShrineOfProsperityPresent_Movement_WatchYoungsterLeave
	applymovement LOCALID_PLAYER, ShrineOfProsperityPresent_Movement_WatchYoungsterLeave
	waitmovement VAR_TEMP_1
	return
	
ShrineOfProsperityPresent_EventScript_ResolutionStopWeather:
	setweather WEATHER_SHADE
	doweather
	delay 40
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceUpExclamationMark
	applymovement LOCALID_PROSPERITY_PRESENT_ANABEL, Common_Movement_FaceRightExclamationMark
	waitmovement 0
	delay 80
	return

ShrineOfProsperityPresent_Movement_PanCameraToResolutionPosition:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

ShrineOfProsperityPresent_Movement_LookerWalkUpResolution:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	delay_16
	delay_8
	face_up
	step_end

ShrineOfProsperityPresent_Movement_CulpritWalkUpResolution:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	face_up
	step_end

ShrineOfProsperityPresent_Movement_AnabelWalkUpResolution:
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	face_up
	step_end

ShrineOfProsperityPresent_Movement_CulpritLeave:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperityPresent_Movement_YoungsterLeave:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ShrineOfProsperityPresent_Movement_WatchYoungsterLeave:
	face_left
	delay_16
	delay_16
	face_down
	step_end
	
ShrineOfProsperityPresent_Movement_WatchCulpritLeave:
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end

ShrineOfProsperityPresent_Movement_LandorusWalkToLooker:
	walk_down
	walk_left
	face_down
	step_end

ShrineOfProsperityPresent_Movement_LandorusFlyOff:
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

ShrineOfProsperityPresent_Movement_AnabelLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ShrineOfProsperityPresent_Movement_LookerLeave:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShrineOfProsperityPresent_EventScript_TastyMint::
	goto_if_set FLAG_HIDDEN_ITEM_SHRINE_PROSPERITY_PRESENT_TASTY_MINT, Common_EventScript_End
	lock
	waitse
	giveitem ITEM_SERIOUS_MINT, 1
	closemessage
	setflag FLAG_HIDDEN_ITEM_SHRINE_PROSPERITY_PRESENT_TASTY_MINT
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_FIND_TASTY_MINT
	call_if_eq VAR_RESULT, TRUE, Past_House2_EventScript_SetTastyMintReward
	release
	end

ShrineOfProsperityPresent_EventScript_StartGenieFight::
	lockall
	faceplayer
	clearflag FLAG_HIDE_SHRINE_THUNDURUS
	speakername Name_Tornadus
	message ShrineOfProsperityPresent_Text_Tornadus
	playmoncry SPECIES_TORNADUS, CRY_MODE_NORMAL
	waitmoncry
	waitmessage
	closemessage
	setobjectxyperm LOCALID_SHRINE_THUNDURUS, 12, 16
	addobject LOCALID_SHRINE_THUNDURUS
	delay 40
	call_if_eq VAR_FACING, DIR_NORTH, ShrineOfProsperityPresent_EventScript_ThundurusRushN
	call_if_eq VAR_FACING, DIR_EAST, ShrineOfProsperityPresent_EventScript_ThundurusRushE
	call_if_eq VAR_FACING, DIR_WEST, ShrineOfProsperityPresent_EventScript_ThundurusRushW
	speakername Name_Thundurus
	message ShrineOfProsperityPresent_Text_Thundurus
	playmoncry SPECIES_THUNDURUS, CRY_MODE_ENCOUNTER
	waitmoncry
	waitmessage
	closemessage
	createmon 1, 0, SPECIES_TORNADUS, 60, ITEM_KINGS_ROCK, 1, NATURE_SERIOUS, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_BLEAKWIND_STORM, MOVE_FLY, MOVE_HAMMER_ARM, MOVE_KNOCK_OFF
	createmon 1, 1, SPECIES_THUNDURUS, 60, ITEM_KINGS_ROCK, 1, NATURE_SERIOUS, 0, MON_MALE, 0, 0, 0, 0, 0, 0, 15, 15, 15, 15, 15, 15, MOVE_WILDBOLT_STORM, MOVE_FLY, MOVE_SUPERPOWER, MOVE_THUNDER_WAVE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattleDouble
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ShrineOfProsperityPresent_EventScript_DefeatedGenies
	releaseall
	end

ShrineOfProsperityPresent_EventScript_ThundurusRushN::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushN
	waitmovement 0
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_ThundurusRushE::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushE
	waitmovement 0
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_ThundurusRushW::
	applymovement LOCALID_SHRINE_THUNDURUS, ShrineOfProsperityPresent_Movement_ThundurusRushW
	waitmovement 0
	setobjectmovementtype LOCALID_SHRINE_THUNDURUS, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	return

ShrineOfProsperityPresent_EventScript_DefeatedGenies::
 	delay 40
	speakername Name_Tornadus
	msgbox ShrineOfProsperityPresent_Text_TornadusDefeat, MSGBOX_DEFAULT
	speakername Name_Thundurus
	msgbox ShrineOfProsperityPresent_Text_ThundurusDefeat, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, ShrineOfProsperityPresent_EventScript_GeniesEscapeN
	call_if_eq VAR_FACING, DIR_EAST, ShrineOfProsperityPresent_EventScript_GeniesEscapeE
	call_if_eq VAR_FACING, DIR_WEST, ShrineOfProsperityPresent_EventScript_GeniesEscapeW
	removeobject LOCALID_SHRINE_TORNADUS
	removeobject LOCALID_SHRINE_THUNDURUS
	delay 40
	speakername Name_Looker
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
	speakername Name_Looker
	msgbox ShrineOfProsperityPresent_Text_LookerTheWeather, MSGBOX_DEFAULT
	closemessage
	@playbgm MUS_DP_ETERNA_FOREST, TRUE
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INVESTIGATE_PROSPERITY, 0
	questmenu QUEST_MENU_SET_REWARD QUEST_INVESTIGATE_PROSPERITY
	setflag FLAG_SYS_DISABLE_ENCOUNTERS
	clearflag FLAG_HIDE_OUTSIDE_NPCS
	clearflag FLAG_HIDE_TORNADUS_NPCS
	clearflag FLAG_BOYFRIEND_WENT_OUT
	clearflag FLAG_HIDE_PORT_FAITHFUL_MAN
	clearflag FLAG_HIDE_PORT_AROMATISSE
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
	speakername Name_Looker
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
	.string "Graaaaargh!$"

ShrineOfProsperityPresent_Text_Thundurus:
	.string "Gyuuuuoooooh!$"
	
ShrineOfProsperityPresent_Text_TornadusDefeat:
	.string "Grrrrrr…$"

ShrineOfProsperityPresent_Text_ThundurusDefeat:
	.string "Graaaah…$"

ShrineOfProsperityPresent_Text_LookerAreThosePokeballs:
	.string "Huh?\n"
	.string "Are those…\p"
	.string "Pokéballs on the ground?$"

ShrineOfProsperityPresent_Text_LookerReportBack:
	.string "Hmm…\p"
	.string "The rangers will be sure to find this\n"
	.string "interesting…$"

ShrineOfProsperityPresent_Text_LookerTheWeather:
	.string "The weather…\n"
	.string "It's clearing up!$"

ShrineOfProsperityPresent_Text_AnabelItsTime:
	.string "It's time.\n"
	.string "Are you ready to release Landorus?$"

ShrineOfProsperityPresent_Text_YoungsterYes:
	.string "Yup…$"

ShrineOfProsperityPresent_Text_BlueYes:
	.string "Let's just get this over with…$"

ShrineOfProsperityPresent_Text_MayYes:
	.string "Ready when you are!$"

ShrineOfProsperityPresent_Text_AceTrainerYes:
	.string "Whatever…$"

ShrineOfProsperityPresent_Text_Leaf:
	.string "(nods)$"

ShrineOfProsperityPresent_Text_AnabelLandorusGoFree:
	.string "All right then.\p"
	.string "Landorus, go free!$"

ShrineOfProsperityPresent_Text_LandorusWasSetFree:
	.string "Landorus was set free!$"

ShrineOfProsperityPresent_Text_BlueBye:
	.string "Well, smell ya later…$"

ShrineOfProsperityPresent_Text_MayBye:
	.string "I think my job here is done!\n"
	.string "See you around!$"

ShrineOfProsperityPresent_Text_LeafBye:
	.string "…$"

ShrineOfProsperityPresent_Text_AceTrainerBye:
	.string "What a waste of time…$"

ShrineOfProsperityPresent_Text_YoungsterBye:
	.string "Snivel…\p"
	.string "Waaah!$"

ShrineOfProsperityPresent_Text_Landorus:
	.string "Gwuoooouh!$"

ShrineOfProsperityPresent_Text_LandorusLook:
	.string "Landorus gave Looker a look of\n"
	.string "familiarity…$"

ShrineOfProsperityPresent_Text_AnabelThatsThat:
	.string "Well, that's that.\p"
	.string "I'm ready to head out of the city\n"
	.string "whenever you are.\p"
	.string "I kind of miss Unova.$"

ShrineOfProsperityPresent_Text_LookerIndeed:
	.string "Agreed.\p"
	.string "I remember the next trip out of the\n"
	.string "city was a few days for now.\p"
	.string "Might as well make the most of the rest\n"
	.string "of our time here, hmm…?$"

ShrineOfProsperityPresent_Text_AnabelSoundsLikeAPlan:
	.string "Sounds like a plan!\p"
	.string "Beach days on the clock, here we come!$"

Epilogue_Text_AFewDaysLater:
	.string "A few days later…$"
