PresentTown_Port_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PresentTown_Port_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PresentTown_Port_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PresentTown_Port_OnResume
	.byte 0

PresentTown_Port_OnResume:
	special HealPlayerParty
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PresentTown_Port_EventScript_TryRemoveThundurus
	end
	
PresentTown_Port_EventScript_TryRemoveThundurus::
	specialvar VAR_RESULT, GetBattleOutcome
	call_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PresentTown_Port_EventScript_RemoveThundurus
	return

PresentTown_Port_EventScript_RemoveThundurus::
	setflag FLAG_CAUGHT_THUNDURUS
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	removeobject LOCALID_CITY_THUNDURUS
	addvar VAR_CATCH_GENIES_QUEST, 1
	return

PresentTown_Port_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetStormWeather
	call_if_eq VAR_CUTSCENE_STATE, 0, PresentTown_Port_SetUpArrival
	call_if_eq VAR_CUTSCENE_STATE, 14, PresentTown_Port_SetUpDeparture
	end

PresentTown_Port_SetUpArrival::
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 16, 7
	setobjectxyperm LOCALID_PORT_SHIP, 3, 9
	return

PresentTown_Port_SetUpDeparture::
	call_if_unset FLAG_HIDE_SS_TIDAL, PresentTown_Port_DepartOnShip
	call_if_unset FLAG_HIDE_TINY_BOAT, PresentTown_Port_DepartOnBoat
	setobjectxyperm LOCALID_PORT_ANABEL, 10, 10
	setobjectxyperm LOCALID_PRESENT_PORT_LUVDISC, 7, 7
	setobjectmovementtype LOCALID_PORT_ANABEL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype VAR_TEMP_1, MOVEMENT_TYPE_FACE_LEFT
	return

PresentTown_Port_DepartOnShip::
	setvar VAR_TEMP_1, LOCALID_PORT_SHIP
	return

PresentTown_Port_DepartOnBoat::
	setvar VAR_TEMP_1, LOCALID_PORT_BOAT
	return
	
PresentTown_Port_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 0, PresentTown_Port_EventScript_Arrival
	map_script_2 VAR_CATCH_GENIES_QUEST, 4, PresentTown_Port_EventScript_FinishGeniesQuest
	map_script_2 VAR_CUTSCENE_STATE, 14, PresentTown_Port_EventScript_Departure
	.2byte 0

PresentTown_Port_EventScript_FinishGeniesQuest::
	lock
	delay 30
	speakername Name_Looker
	msgbox PresentTown_Text_LookerTheSpiritsAreCaught, MSGBOX_DEFAULT
	completequest QUEST_CATCH_GENIES
	addvar VAR_CATCH_GENIES_QUEST, 1
	release
	end

PresentTown_Port_EventScript_Departure::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, PresentTown_Port_Movement_PanCameraToDeparturePanStart
	waitmovement 0
	applymovement LOCALID_CAMERA, PresentTown_Port_Movement_PanCameraToDeparture
	fadescreen FADE_FROM_BLACK
	delay 60
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerWalkToShip
	waitmovement 0
	delay 60
	playse SE_EXIT
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	applymovement LOCALID_PORT_ANABEL, PresentTown_Port_Movement_AnabelWalkOntoShip
	waitmovement LOCALID_PLAYER
	playse SE_EXIT
	applymovement LOCALID_PLAYER, Common_Movement_SetInvisible
	waitmovement LOCALID_PORT_ANABEL
	removeobject LOCALID_PORT_ANABEL
	waitmovement LOCALID_CAMERA
	delay 100
	playse SE_SHIP
	delay 20
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_EndGame
	applymovement VAR_TEMP_1, PresentTown_Port_Movement_EndGame
	waitmovement 0
	delay 80
	fadescreen FADE_TO_BLACK
	clearflag FLAG_HIDE_PORT_BLUE
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	setvar VAR_CUTSCENE_STATE, 15
	special RemoveCameraObject
	delay 120
	setrespawn HEAL_LOCATION_PRESENT
	special SetChampionSaveWarp
	special GameClear
	waitstate
	releaseall
	end

@ 14 10 to 22 10
PresentTown_Port_Movement_PanCameraToDeparturePanStart::
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	walk_faster_right	
	@walk_faster_right	
	@walk_faster_right	
	@walk_faster_right	
	step_end

PresentTown_Port_Movement_LookerWalkToShip:
	walk_left
	walk_left
	walk_left
	step_end

PresentTown_Port_Movement_AnabelWalkOntoShip:
	walk_right
	walk_up
	step_end

@ 22 10 to 11 10
PresentTown_Port_Movement_PanCameraToDeparture:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

PresentTown_Port_EventScript_Arrival::
	lockall
	playse SE_SHIP
	applymovement LOCALID_PORT_SHIP, PresentTown_Port_Movement_ShipPullIntoPort
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_ShipPullIntoPort
	fadescreen FADE_FROM_BLACK
	delay 90
	playse SE_TRUCK_DOOR
	waitse
	delay 10
	applymovement LOCALID_PORT_ANABEL, PresentTown_Port_Movement_AnabelExitShip
	waitmovement 0
	speakername Name_Anabel
	msgbox PresentTown_Port_Text_AnabelWeveArrived, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_PORT_ANABEL, PresentTown_Port_Movement_AnabelStepAside
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerExitShip
	waitmovement 0
	speakername Name_Looker
	msgbox PresentTown_Port_Text_LookerSoWeHave, MSGBOX_DEFAULT
	speak LOCALID_PORT_ANABEL, DIR_WEST, Name_Anabel, PresentTown_Port_Text_AnabelTheCityIsUpAhead
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, PresentTown_Port_Text_LookerSoundsLikeAPlan
	speak LOCALID_PORT_ANABEL, DIR_WEST, Name_Anabel, PresentTown_Port_Text_AnabelMeetUpWithMe
	closemessage
	applymovement LOCALID_PORT_ANABEL, PresentTown_Port_Movement_AnabelExitShot
	waitmovement 0
	removeobject LOCALID_PORT_ANABEL
	additem ITEM_HP_MOCHI, 1
	additem ITEM_ATK_MOCHI, 3
	additem ITEM_DEF_MOCHI, 1
	additem ITEM_SPDEF_MOCHI, 1
	additem ITEM_SPE_MOCHI, 2
	givemonwithot OT_LOOKER_GROWLITHE
	givemonwithot OT_LOOKER_TOXICROAK
	setrespawn HEAL_LOCATION_PRESENT
	special EnableNationalPokedex
	setvar VAR_CUTSCENE_STATE, 1
	setobjectxyperm LOCALID_PORT_SHIP, 10, 9
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	clearflag FLAG_SYS_SPAWN_INVISIBLE
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	releaseall
	end

PresentTown_Port_Movement_ShipPullIntoPort:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PresentTown_Port_Movement_EndGame:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

PresentTown_Port_Movement_LookerExitShip:
	face_down
	set_visible
	walk_down
	face_right
	step_end

PresentTown_Port_Movement_AnabelExitShip:
	set_visible
	walk_down
	face_up
	step_end

PresentTown_Port_Movement_AnabelStepAside:
	walk_right
	face_left
	step_end

PresentTown_Port_Movement_AnabelExitShot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PresentTown_Port_EventScript_MagikarpManTrigger1::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_ExclamationMark
	delay 48
	goto PresentTown_Port_EventScript_MagikarpManInitialOffer
	end
	
PresentTown_Port_EventScript_MagikarpManTrigger2::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_ExclamationMark
	delay 48
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkRight
	goto PresentTown_Port_EventScript_MagikarpManInitialOffer
	end

PresentTown_Port_EventScript_MagikarpManInitialOffer::
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	showmoneybox 0, 0
	msgbox PresentTown_Port_Text_MagikarpManYouWantAMagikarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerNotInterested
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerPositive
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManOhFine, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 17, PresentTown_Port_EventScript_LookerStepAside
	call_if_eq VAR_TEMP_0, 18, PresentTown_Port_EventScript_MagikarpManWalkToBench
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 21, 8
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_CUTSCENE_STATE, 2
	releaseall
	end
	
PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger::
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerSupportLocalBusiness
	removemoney 3000
	updatemoneybox
	playse SE_SHOP
	speak LOCALID_PORT_MAGIKARPMAN, DIR_EAST, Name_Magikarp_Man, PresentTown_Port_Text_MagikarpManRememberNoTakebacks
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
    givemonwithot OT_LOOKER_MAGIKARP
	speakername NULL
	call PresentTown_Port_EventScript_ReceivedMagikarpFanfare
	closemessage
	hidemoneybox
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 17, PresentTown_Port_EventScript_LookerStepAside
	call_if_eq VAR_TEMP_0, 18, PresentTown_Port_EventScript_MagikarpManWalkToBench
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 21, 8
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_LEFT
	setvar VAR_CUTSCENE_STATE, 2
	releaseall
	end

PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromBench::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerSupportLocalBusiness
	removemoney 3000
	updatemoneybox
	playse SE_SHOP
	speak LOCALID_PORT_MAGIKARPMAN, VAR_0x8005, Name_Magikarp_Man, PresentTown_Port_Text_MagikarpManRememberNoTakebacks
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
    givemonwithot OT_LOOKER_MAGIKARP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PresentTown_Port_EventScript_ReceiveMagikarpParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PresentTown_Port_EventScript_ReceiveMagikarpPC
	call Common_EventScript_NoMoreRoomForPokemon
	end

PresentTown_Port_EventScript_ReceiveMagikarpParty::
	call PresentTown_Port_EventScript_ReceivedMagikarpFanfare
	goto PresentTown_Port_EventScript_FinishGiveMagikarp
	end
	
PresentTown_Port_EventScript_ReceiveMagikarpPC::
	call PresentTown_Port_EventScript_ReceivedMagikarpFanfare
	call Common_EventScript_TransferredToPC
	goto PresentTown_Port_EventScript_FinishGiveMagikarp
	end

PresentTown_Port_EventScript_ReceivedMagikarpFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MAGIKARP
	playfanfare MUS_OBTAIN_ITEM
	speakername NULL
	msgbox Present_Gym_Text_YouReceivedMagikarp, MSGBOX_DEFAULT
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	setflag FLAG_PURCHASED_MAGIKARP
	return

PresentTown_Port_EventScript_LookerStepAside::
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerStepAside
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_PORT_MAGIKARPMAN, PresentTown_Port_Movement_MagikarpManWalkToBench
	waitmovement 0
	return
	
PresentTown_Port_EventScript_FinishGiveMagikarp::
	@ speak LOCALID_PORT_MAGIKARPMAN, VAR_0x8005, Name_Magikarp_Man, PresentTown_Port_Text_MagikarpManRememberNoTakebacks
	closemessage
	hidemoneybox
	releaseall
	end

PresentTown_Port_EventScript_MagikarpManWalkToBench::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_PORT_MAGIKARPMAN, PresentTown_Port_Movement_MagikarpManWalkToBench
	waitmovement 0
	return

PresentTown_Port_EventScript_MagikarpMan::
	lockall
	faceplayer
	goto_if_set FLAG_PURCHASED_MAGIKARP, PresentTown_Port_EventScript_MagikarpManNoTakebacks
	call Script_GetNPCFacingDirection
	speakername Name_Magikarp_Man
	showmoneybox 0, 0
	msgbox PresentTown_Port_Text_MagikarpManYouSureYouDontWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromBench
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerNotInterested
	closemessage
	hidemoneybox
	releaseall
	end
	
PresentTown_Port_EventScript_MagikarpManNoTakebacks::
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManNoRefunds, MSGBOX_DEFAULT
	speakername Name_Looker
	msgbox PresentTown_Port_Text_LookerDots, MSGBOX_DEFAULT
	closemessage
	release
	end

PresentTown_Port_Movement_LookerStepAside:
	walk_right
	face_down
	step_end

PresentTown_Port_Movement_MagikarpManWalkToBench:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	face_left
	step_end


PresentTown_Port_EventScript_Thundurus::
	lock
	faceplayer
	waitse
	setflag FLAG_SYS_NO_WHITEOUT
	playmoncry SPECIES_THUNDURUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_THUNDURUS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	clearflag FLAG_SYS_NO_WHITEOUT
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PresentTown_Port_EventScript_DefeatedThundurus
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_Port_EventScript_RanFromThundurus
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_Port_EventScript_RanFromThundurus
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PresentTown_Port_EventScript_RanFromThundurus
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	removeobject VAR_LAST_TALKED
	call Common_EventScript_MoveInsideNPCsOutside
	release
	end

PresentTown_Port_EventScript_DefeatedThundurus::
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	goto Common_EventScript_RemoveStaticPokemon
	end

PresentTown_Port_EventScript_RanFromThundurus::
	clearflag FLAG_SYS_WEATHER_CTRL
	setweather WEATHER_SUNNY
	doweather
	call Common_EventScript_MoveInsideNPCsOutside
	setvar VAR_0x8004, SPECIES_THUNDURUS
	goto Common_EventScript_LegendaryFlewAway
	end

PresentTown_Port_EventScript_Blue::
	lock
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PresentTown_Port_EventScript_BluePreGame
	returnqueststate QUEST_FIND_THE_CULPRIT
    switch VAR_RESULT
	case 1, PresentTown_Port_EventScript_BluePreQuest
	case 2, PresentTown_Port_EventScript_BlueQuest
	case 4, PresentTown_Port_EventScript_BluePostQuest
	release
	end

PresentTown_Port_EventScript_BluePreGame::
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerWouldYouKnow
	speak LOCALID_BLUE, VAR_FACING, Name_Blue, PresentTown_Port_Text_BluePreQuest
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerOhMyApologies
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_EventScript_BluePreQuest::
	faceplayer
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerToBluePreQuest
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BluePreQuest
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerOhMyApologies
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_EventScript_BlueQuest::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FIND_THE_CULPRIT, 0
	goto_if_eq VAR_RESULT, TRUE, PresentTown_Port_EventScript_BluePostQuest
    setflag FLAG_SYS_DISAPPEAR_QUESTS
    playbgm MUS_PL_LOOKER, TRUE
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_YouAreUnderSuspicion
	call_if_eq VAR_FACING, DIR_NORTH, PresentTown_Port_EventScript_BlueTurnFaceLookerNorth
	call_if_ne VAR_FACING, DIR_NORTH, PresentTown_Port_EventScript_BlueTurnFaceLooker
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueImSorryWhat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnowYouDidIt
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueWhat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ComingWithMe
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueFine
	goto_if_eq VAR_CHOOSE_CULPRIT, 0, PresentTown_Port_EventScript_BlueCulpritQuest
	setflag FLAG_SYS_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_BLUE, PresentTown_Port_Text_BlueDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_Port_EventScript_BlueDefeat
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_Port_EventScript_BlueDefeat
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 0
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
	fadedefaultbgm
	goto PresentTown_Port_EventScript_BluePostQuest
	release
	end

PresentTown_Port_EventScript_BlueCulpritQuest::
	setflag FLAG_SYS_NO_WHITEOUT
	trainerbattle_no_intro TRAINER_BLUE_CULPRIT, PresentTown_Port_Text_BlueCulpritDefeated
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_Port_EventScript_BlueDefeat
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_Port_EventScript_BlueDefeat
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IKnewItWasYou
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueIHadItTheWholeTime
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerAhARivalry
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueTakingMeToCityHall
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerSoLongAsYouRelease
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueUghFine
	closemessage
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT, 0
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_FIND_THE_CULPRIT
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_HIDE_SHRINE_BLUE
    clearflag FLAG_HIDE_SHRINE_PROSPERITY_PRESENT_ANABEL
    setflag FLAG_SYS_PREVENT_MAP_FADE
	setvar VAR_CUTSCENE_STATE, 14
    warp MAP_SHRINE_OF_PROSPERITY_PRESENT, 12, 16
	waitstate
	release
	end

PresentTown_Port_EventScript_BlueTurnFaceLookerNorth::
	playse SE_PIN
	applymovement LOCALID_BLUE, Common_Movement_FaceDownQuestionMark
	waitmovement 0
	delay 50
	return

PresentTown_Port_EventScript_BlueTurnFaceLooker::
	playse SE_PIN
	applymovement LOCALID_BLUE, Common_Movement_FaceRightQuestionMark
	waitmovement 0
	delay 50
	return

PresentTown_Port_EventScript_BlueDefeat::
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueLayOffMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Hmm
	closemessage
	fadedefaultbgm
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
    clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_SYS_NO_WHITEOUT
	release
	end

PresentTown_Port_EventScript_BluePostQuest::
	goto_if_eq VAR_CHOOSE_CULPRIT, 0, PresentTown_Port_EventScript_BlueCulpritPostQuest
	goto_if_unset FLAG_BLUE_GAVE_POKEMON, PresentTown_Port_EventScript_BluePostQuestGiveMon
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueGetOffMyBack
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerSorry
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
PresentTown_Port_EventScript_BluePostQuestGiveMon::
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueGivePokemon
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_UhhOkay
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueGreatYouWantPokemon
	setflag FLAG_BLUE_GAVE_POKEMON
	multichoice MULTI_BLUE_GIVEMON, 0, 6, TRUE
	goto_if_eq VAR_RESULT, 0, PresentTown_Port_EventScript_BlueGiveGolem
	goto_if_eq VAR_RESULT, 1, PresentTown_Port_EventScript_BlueGiveMachamp
	release
	end

PresentTown_Port_EventScript_BlueCulpritPostQuest::
	goto_if_unset FLAG_BLUE_GAVE_POKEMON, PresentTown_Port_EventScript_BlueCulpritPostQuestGiveMon
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueYouHappy
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerICanLetYouOffTheHook
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueUgh
	closemessage
	applymovement LOCALID_BLUE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_EventScript_BlueCulpritPostQuestGiveMon::
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueYouHappyGiveMon
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_UhhOkay
	speak LOCALID_BLUE, VAR_0x8005, Name_Blue, PresentTown_Port_Text_BlueGreatYouWantPokemon
	setflag FLAG_BLUE_GAVE_POKEMON
	multichoice MULTI_BLUE_GIVEMON, 0, 6, TRUE
	goto_if_eq VAR_RESULT, 0, PresentTown_Port_EventScript_BlueGiveGolem
	goto_if_eq VAR_RESULT, 1, PresentTown_Port_EventScript_BlueGiveMachamp
	release
	end
	
PresentTown_Port_EventScript_FaithfulMan::
	lockall
	returnqueststate QUEST_FOREVER_FAITHFUL
	goto_if_eq VAR_RESULT, 1, PresentTown_Port_EventScript_BoyfriendPreQuest
	call Script_GetNPCFacingDirection
	speak LOCALID_PORT_BOYFRIEND, DIR_WEST, Name_Boyfriend, PresentTown_Port_Text_BoyfriendPrequest
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerThatIsAnAromatisse
	closemessage
	playse SE_PIN
	call_if_eq VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendFaceRight
	call_if_ne VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendFaceUp
	speak LOCALID_PORT_BOYFRIEND, VAR_0x8005, Name_Boyfriend, PresentTown_Port_Text_BoyfriendHuh
	applymovement LOCALID_PORT_BOYFRIEND, Common_Movement_FaceLeft
	playse SE_SELECT
	msgbox PresentTown_Port_Text_BoyfriendWait, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_AROMATISSE, CRY_MODE_NORMAL
	speak LOCALID_PORT_AROMATISSE, DIR_EAST, Name_Aromatisse, PresentTown_Port_Text_AromatisseControls
	waitmoncry
	speak LOCALID_PORT_BOYFRIEND, VAR_0x8005, Name_Boyfriend, PresentTown_Port_Text_BoyfriendThatsUhh
	playse SE_SELECT
	call_if_eq VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendFaceRight
	call_if_ne VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendFaceUp	
	trainerbattle_no_intro TRAINER_BOYFRIEND, PresentTown_Port_Text_BoyfriendDefeat
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, PresentTown_Port_EventScript_FaithfulManDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PresentTown_Port_EventScript_FaithfulManDefeated
	speak LOCALID_PORT_BOYFRIEND, VAR_0x8005, Name_Boyfriend, PresentTown_Port_Text_BoyfriendComingToSenses
	closemessage
	delay 60
	playse SE_PIN
	applymovement LOCALID_PORT_BOYFRIEND, Common_Movement_FaceLeftExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_PORT_BOYFRIEND, DIR_WEST, Name_Boyfriend, PresentTown_Port_Text_BoyfriendWhatAreYou
	playmoncry SPECIES_AROMATISSE, CRY_MODE_NORMAL
	speak LOCALID_PORT_AROMATISSE, DIR_EAST, Name_Aromatisse, PresentTown_Port_Text_AromatisseStartled
	waitmoncry
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_AromatisseRunOffUp
	call_if_ne VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_AromatisseRunOffRight
	removeobject LOCALID_PORT_AROMATISSE
	speak LOCALID_PORT_BOYFRIEND, VAR_0x8005, Name_Boyfriend, PresentTown_Port_Text_BoyfriendBackToMyBaby
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendRunOffUp
	call_if_ne VAR_FACING, DIR_WEST, PresentTown_Port_EventScript_BoyfriendRunOffRight
	removeobject LOCALID_PORT_BOYFRIEND
	questmenu QUEST_MENU_SET_REWARD, QUEST_FOREVER_FAITHFUL
	releaseall
	end

PresentTown_Port_EventScript_BoyfriendFaceUp:
	applymovement LOCALID_PORT_BOYFRIEND, Common_Movement_FaceUpQuestionMark
	waitmovement 0
	delay 50
	return
	

PresentTown_Port_EventScript_BoyfriendFaceRight:
	applymovement LOCALID_PORT_BOYFRIEND, Common_Movement_FaceRightQuestionMark
	waitmovement 0
	delay 50
	return

PresentTown_Port_EventScript_AromatisseRunOffUp::
	applymovement LOCALID_PORT_BOYFRIEND, PresentTown_Port_Movement_BoyfriendWatchAromatisse
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerWatchAromatisse
	applymovement LOCALID_PORT_AROMATISSE, PresentTown_Port_Movement_AromatisseRunOffUp
	waitmovement 0
	return

PresentTown_Port_EventScript_AromatisseRunOffRight::
	applymovement LOCALID_PORT_BOYFRIEND, PresentTown_Port_Movement_BoyfriendWatchAromatisse
	applymovement LOCALID_PORT_AROMATISSE, PresentTown_Port_Movement_AromatisseRunOffRight
	playse SE_EFFECTIVE
	speakername Name_Looker
	message Looker_Text_Ouch
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerPushedByAromatisse
	waitmessage
	delay 40
	closemessage
	waitmovement LOCALID_PORT_AROMATISSE
	delay 40
	applymovement LOCALID_PLAYER, PresentTown_Port_Movement_LookerWalkBackInPlace
	return

PresentTown_Port_Movement_LookerWatchAromatisse:
	delay_16
	delay_8
	face_up
	delay_8
	face_right
	delay_16
	delay_16
	face_up
	step_end

PresentTown_Port_Movement_BoyfriendWatchAromatisse:
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	step_end

PresentTown_Port_Movement_AromatisseRunOffUp:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Port_Movement_AromatisseRunOffRight:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Port_Movement_LookerPushedByAromatisse:
	delay_16
	lock_facing_direction
	walk_faster_right
	walk_faster_right
	unlock_facing_direction
	delay_16
	delay_16
	face_right
	delay_16
	face_up
	step_end

PresentTown_Port_Movement_LookerWalkBackInPlace:
	walk_left
	walk_left
	face_down
	step_end

PresentTown_Port_EventScript_BoyfriendRunOffUp::
	applymovement LOCALID_PORT_BOYFRIEND, PresentTown_Port_Movement_BoyfriendRunOffUp
	waitmovement 0
	return

PresentTown_Port_EventScript_BoyfriendRunOffRight::
	applymovement LOCALID_PORT_BOYFRIEND, PresentTown_Port_Movement_BoyfriendRunOffRight
	waitmovement 0
	return

PresentTown_Port_Movement_BoyfriendRunOffUp:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Port_Movement_BoyfriendRunOffRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PresentTown_Port_EventScript_BoyfriendPreQuest::
	speakername Name_Boyfriend
	msgbox PresentTown_Port_Text_BoyfriendPrequest, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PresentTown_Port_EventScript_FaithfulManDefeated::
	speak LOCALID_PORT_BOYFRIEND, VAR_0x8005, Name_Boyfriend, PresentTown_Port_Text_BoyfriendWon
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Drat
	closemessage
	clearflag FLAG_SYS_NO_WHITEOUT
	releaseall
	end

PresentTown_Port_EventScript_Aromatisse::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AROMATISSE, CRY_MODE_NORMAL
	msgbox PresentTown_Port_Text_Aromatisse, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_PORT_AROMATISSE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PresentTown_Port_Text_LookerThatIsAnAromatisse:
	.string "Uh, sir? Are you okay?\p"
	.string "That is an Aromatisse you are speaking\n"
	.string "with.$"

PresentTown_Port_Text_BoyfriendHuh:
	.string "Hmm… huh…?$"

PresentTown_Port_Text_BoyfriendWait:
	.string "Wait… is that…?$"

PresentTown_Port_Text_BoyfriendThatsUhh:
	.string "That's… uhh…\p"
	.string "…Mmm…$"

PresentTown_Port_Text_BoyfriendPrefight:
	.string "You won't get my sweet baby…\p"
	.string "Baby…$"

PresentTown_Port_Text_BoyfriendWon:
	.string "Don't touch my smells…\p"
	.string "So sweet and fruity…$"

PresentTown_Port_Text_BoyfriendDefeat:
	.string "…Mmm…\p"
	.string "Ahh…\p"
	.string "Uhh…\p"
	.string "Wait, huh?$"

PresentTown_Port_Text_BoyfriendComingToSenses:
	.string "Ahhh…\n"
	.string "Huh?\p"
	.string "Hold on!$"

PresentTown_Port_Text_BoyfriendWhatAreYou:
	.string "Ahh!\p"
	.string "You're not my sweetie pie!\p"
	.string "You're a POKéMON!$"

PresentTown_Port_Text_BoyfriendBackToMyBaby:
	.string "Thanks for breaking me out of that\n"
	.string "sweet smelling spell!\p"
	.string "I need to get back to my baby,\n"
	.string "PRONTO!$"
	
PresentTown_Port_Text_BoyfriendPrequest:
	.string "Oh babycakes…\p"
	.string "You smell so good…\p"
	.string "Like cherries and lemons…\p"
	.string "Stay with me forever…$"

PresentTown_Port_Text_Aromatisse:
	.string "Ara-ara-ara-ara-ara!$"

PresentTown_Port_Text_AromatisseControls:
	.string "Ara?\n"
	.string "Aaaaaaaaaah!$"

PresentTown_Port_Text_AromatisseStartled:
	.string "Ara!?$"

PresentTown_Port_Text_LookerWouldYouKnow:
	.string "Hello, citizen.\p"
	.string "My name…\n"
	.string "Is Looker.\p"
	.string "I believe there is something evil afoot\n"
	.string "regarding Team Aqua!\p"
	.string "Young man, would you happen to know if\n"
	.string "they have been causing trouble?$"

PresentTown_Port_Text_BlueImSorryWhat:
	.string "Huh? What are you blabbering about?$"

PresentTown_Port_Text_BlueWhat:	
	.string "Dude, I didn't do any of that…\p"
	.string "Why are you so aggressive? Where the\n"
	.string "heck did you even come from?$"

PresentTown_Port_Text_BlueFine:
	.string "Fine!\p"
	.string "If I can't convince you I didn't screw\n"
	.string "with the wildlife here, then maybe I\l"
	.string "should get you off my back the hard way!$"

PresentTown_Port_Text_BlueDefeated:
	.string "There, now can you get off my back!?\p"
	.string "You're cramping my style!$"

PresentTown_Port_Text_BlueLayOffMe:
	.string "Lay off me, old man! I ain't doin'\n"
	.string "anything wrong!$"

PresentTown_Port_Text_BlueCulpritDefeated:
	.string "Ugh…$"

PresentTown_Port_Text_BlueGivePokemon:
	.string "There, you see? I DON'T have Landorus!\n"
	.string "You wanna give me some space?\p"
	.string "I'll even give you one of my Pokémon if\n"
	.string "it gets you to scram faster!$"

PresentTown_Port_Text_BlueGreatYouWantPokemon:
	.string "Great… You want Machamp or Golem?$"

PresentTown_Port_Text_BlueNowGetOffMe:
	.string "Now get off my back, you blockhead!$"
	
PresentTown_Port_Text_BlueGetOffMyBack:
	.string "There, you see? I DON'T have Landorus!\n"
	.string "Now get off my back, you blockhead!$"

PresentTown_Port_Text_LookerSorry:
	.string "My apologies! Please, enjoy your time in\n"
	.string "Porta Bella!$"

PresentTown_Port_Text_BlueIHadItTheWholeTime:
	.string "Urgh… Okay… You happy?\n"
	.string "I had Landorus the whole time…\p"
	.string "I just wanted to try my hand at taking\n"
	.string "on a legendary Pokémon, 'kay…?\p"
	.string "That punk Red has done nothing but\n"
	.string "one-up me since the beginning…\p"
	.string "I just wanted SOMETHING over him…$"

PresentTown_Port_Text_LookerAhARivalry:
	.string "Ah! A rivaly!\p"
	.string "A compelling reason to try and capture\n"
	.string "a strong Pokémon!\p"
	.string "I remember the fires of my own youth…$\p"

PresentTown_Port_Text_BlueTakingMeToCityHall:
	.string "So… Are you taking me to City Hall\n"
	.string "then…?$"

PresentTown_Port_Text_LookerSoLongAsYouRelease:
	.string "Hmm…\p"
	.string "So long as you release Landorus into\n"
	.string "the wild, I am willing to overlook\l"
	.string "your transgression, just this once…$"

PresentTown_Port_Text_BlueUghFine:
	.string "Sigh… Guess that's the best I could ask\n"
	.string "for…$"

PresentTown_Port_Text_BlueYouHappy:
	.string "You happy? I had Landorus the whole\n"
	.string "time, okay?\p"
	.string "I just wanted to try my hand at taking on\n"
	.string "a legendary Pokémon, 'kay…?$"

PresentTown_Port_Text_BlueYouHappyGiveMon:
	.string "You happy? I had Landorus the whole\n"
	.string "time, okay?\p"
	.string "I just wanted to try my hand at taking on\n"
	.string "a legendary Pokémon, 'kay…?\p"
	.string "Maybe you can have one of my Pokémon if it\n"
	.string "helps make things right…$"

PresentTown_Port_Text_LookerICanLetYouOffTheHook:
	.string "So long as Landorus is safe and around to\n"
	.string "protect Porta Bella, I am happy!\p"
	.string "I can let you off the hook, young man!\n"
	.string "Just stay out of trouble!$"

PresentTown_Port_Text_BlueUgh:
	.string "Ugh… Fine…$"

PresentTown_Port_Text_LookerToBluePreQuest:
	.string "Hello, citizen.\n"
	.string "I am on the hunt for a missing Landorus!\p"
	.string "Would you happen to know anything about\n"
	.string "the whereabouts of such a Pokémon?$"

PresentTown_Port_Text_BluePreQuest:
	.string "Uh, no? I don't live here.\n"
	.string "I only arrived here yesterday…$"

PresentTown_Port_Text_LookerOhMyApologies:
	.string "Oh, my apologies! Please, carry on!$"

PresentTown_Port_Text_BlueICanTakeAThundurus:
	.string "Heh! I bet I could beat up that\n"
	.string "Thundurus! Wanna see me try?$"

PresentTown_Port_Text_MagikarpManYouSureYouDontWant:
	.string "You suuuuuuure you don't want a\n"
	.string "golden Magikarp?$"

PresentTown_Port_Text_MagikarpManYouWantAMagikarp:
	.string "Heyyyyyy!\p"
	.string "You look absolutely dashing in that\n"
	.string "nice purple suit!\p"
	.string "Say, I have a deal right here I know\n"
	.string "you can't refuse!\p"
	.string "For just a piddling 3000 bucks, I will\n"
	.string "sell you a GOLDEN Magikarp!\p"
	.string "You'll never get another chance at such\n"
	.string "an illustrious, glimmering specimen!\p"
	.string "So buddy, what do you say?\p"
	.string "It's only 3000!$"

PresentTown_Port_Text_LookerNotInterested:
	.string "Not interested.$"

PresentTown_Port_Text_MagikarpManYouSure:
	.string "You suuuuuuure?$"

PresentTown_Port_Text_LookerPositive:
	.string "Positive.$"

PresentTown_Port_Text_MagikarpManOhFine:
	.string "Oh fiiiiiine…\p"
	.string "If you ever change your mind,\n"
	.string "I'll be waiting on that bench…\p"
	.string "(Stickler…)$"

PresentTown_Port_Text_MagikarpManNoRefunds:
	.string "No refunds!$"

PresentTown_Port_Text_LookerSupportLocalBusiness:
	.string "Sure…\p"
	.string "(I suppose I should support local\n"
	.string "business…)$"

PresentTown_Port_Text_MagikarpManRememberNoTakebacks:
	.string "All right then, no take backs!$"

PresentTown_Port_Text_LookerDots:
	.string "…$"
	
PresentTown_Port_Text_AnabelWeveArrived:
	.string "Looker, we've arrived!$"

PresentTown_Port_Text_LookerSoWeHave:
	.string "So we have.$"

PresentTown_Port_Text_AnabelTheCityIsUpAhead:
	.string "First thing's first, I need to touch\n"
	.string "base with the mayor and get the\l"
	.string "paperwork for this case sorted out.\p"
	.string "You should take the time to explore\n"
	.string "the city and scope out Team Aqua.$"

PresentTown_Port_Text_LookerSoundsLikeAPlan:
	.string "Sounds like a plan.$"

PresentTown_Port_Text_AnabelMeetUpWithMe:
	.string "Meet up with me at City Hall after you\n"
	.string "finish your business.\p"
	.string "It's the largest building in the city -\n"
	.string "you can't miss it.$"

Present_Gym_Text_YouReceivedMagikarp:
	.string "You bought a golden Magikarp…!$"
	