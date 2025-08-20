PastTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PastTown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PastTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PastTown_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PastTown_OnResume
	.byte 0

PastTown_OnLoad:
	call_if_unset FLAG_SWEET_TOOTH_WENT_CRAZY, PastTown_EventScript_CloseSweetToothHole
	call_if_unset FLAG_HIDE_PAST_SAD_GIRL_OUTSIDE, PastTown_EventScript_SetUpSadGirlFight
	end

PastTown_EventScript_CloseSweetToothHole::
	setmetatile 15, 26, METATILE_SmallTownWithLab_Past_FixedRoof, FALSE
	return

PastTown_EventScript_SetUpSadGirlFight::
	setobjectxyperm LOCALID_MILTANK, 8, 21
	setobjectxyperm LOCALID_TAUROS, 10, 21
	setobjectmovementtype LOCALID_MILTANK, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectmovementtype LOCALID_TAUROS, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	return

PastTown_OnTransition:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HELP_FISHERMAN
	call_if_eq VAR_RESULT, TRUE, PastTown_EventScript_FishermanPlacement
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FARMLAND_INVASION_3
	call_if_eq VAR_RESULT, FALSE, PastTown_EventScript_HandleFarmPlacements
	call_if_eq VAR_CUTSCENE_STATE, 9, PastTown_EventScript_LassPlacement
	end

PastTown_EventScript_HandleFarmPlacements::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FARMLAND_INVASION_2
	call_if_eq VAR_RESULT, TRUE, PastTown_EventScript_HandleFarmQuest3Placements
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FARMLAND_INVASION_1
	call_if_eq VAR_RESULT, TRUE, PastTown_EventScript_HandleFarmQuest2Placements
	call_if_eq VAR_RESULT, FALSE, PastTown_EventScript_HandleFarmQuest1Placements
	return

PastTown_EventScript_HandleFarmQuest3Placements::
	setobjectxyperm LOCALID_PAST_FOREMAN, 33, 27
	setobjectxyperm LOCALID_PAST_CARROTFARMER, 38, 24
	setobjectxyperm LOCALID_PAST_CABBAGEFARMER, 39, 24
	setobjectmovementtype LOCALID_PAST_FOREMAN, MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT
	setobjectmovementtype LOCALID_PAST_CARROTFARMER, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_PAST_CABBAGEFARMER, MOVEMENT_TYPE_FACE_LEFT
	return

PastTown_EventScript_HandleFarmQuest2Placements::
	setobjectxyperm LOCALID_PAST_CABBAGEFARMER, 39, 27
	setobjectmovementtype LOCALID_PAST_CABBAGEFARMER, MOVEMENT_TYPE_FACE_DOWN
	return

PastTown_EventScript_HandleFarmQuest1Placements::
	call_if_set FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_HandleFarmQuest1PlacementsStart
	return

PastTown_EventScript_HandleFarmQuest1PlacementsStart::
	setobjectxyperm LOCALID_PAST_CARROTFARMER, 31, 27
	setobjectmovementtype LOCALID_PAST_CARROTFARMER, MOVEMENT_TYPE_FACE_DOWN
	return

PastTown_EventScript_FishermanPlacement::
	setobjectxyperm LOCALID_FISHERMAN, 15, 32
	setobjectmovementtype LOCALID_FISHERMAN, MOVEMENT_TYPE_FACE_DOWN
	return

PastTown_EventScript_LassPlacement::
	setobjectxyperm LOCALID_PASTTOWN_LASS, 46, 9
	setobjectmovementtype LOCALID_PASTTOWN_LASS, MOVEMENT_TYPE_FACE_DOWN
	return

PastTown_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 7, PastTown_EventScript_LookerEnters
	.2byte 0

PastTown_EventScript_LookerEnters::
	lockall
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	delay 40
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	speakername Name_Looker
	msgbox PastTown_Text_LookerWhatIsThis, MSGBOX_DEFAULT
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	delay 40
	playse SE_EFFECTIVE
	delay 10
	speakername Name_Looker
	msgbox PastTown_Text_LookerYowch, MSGBOX_DEFAULT
	delay 30
	closemessage
	delay 30
	fadescreen FADE_FROM_BLACK
	delay 60
	speakername Name_Looker
	msgbox PastTown_Text_LookerImNotDreaming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, PastTown_Movement_LookerLookAround
	waitmovement 0
	speakername Name_Looker
	msgbox PastTown_Text_LookerOutOfTheWoods, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CUTSCENE_STATE, 8
	releaseall
	end
	
PastTown_OnResume:
	special HealPlayerParty
	end

PastTown_EventScript_TownHallSign::
	msgbox PastTown_Text_TownHallSign, MSGBOX_SIGN
	end

PastTown_EventScript_TrainerTips::
	msgbox PastTown_Text_TrainerTips, MSGBOX_SIGN
	end
	
PastTown_EventScript_Lass::
	lock
	faceplayer
	goto_if_eq VAR_CUTSCENE_STATE, 9, PastTown_EventScript_LassFightTalked
	speakername Name_Lass
	msgbox PastTown_Text_LassYouCheated, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_LassFightTalked::
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	goto PastTown_EventScript_LassFight
	end
	
PastTown_EventScript_LassTurnLeft::
	lock
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceLeftExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	delay 60
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassTurnRight::
	lock
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 60
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassWalkRight::
	lock
	playbgm MUS_ENCOUNTER_FEMALE, FALSE
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceRightExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	delay 60
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_WalkRight
	waitmovement 0
	setflag FLAG_SYS_FROM_TRIGGER
	goto PastTown_EventScript_LassFight
	end

PastTown_EventScript_LassFight::
	setflag FLAG_SYS_NO_WHITEOUT
	call_if_set FLAG_FOUGHT_LASS, PastTown_EventScript_LassAnotherRound
	call_if_unset FLAG_FOUGHT_LASS, PastTown_EventScript_LassOyGeezer
	trainerbattle_no_intro TRAINER_MARIE, PastTown_Text_LassLoss
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_BeatLass
	special HealPlayerParty
	speakername Name_Lass
	msgbox PastTown_Text_LassNobodyCanBeatMe, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_eq VAR_TEMP_1, 48, PastTown_EventScript_LassWalkBackToPosition
	call_if_set FLAG_SYS_FROM_TRIGGER, PastTown_EventScript_WalkBackBelowTrigger
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_FaceDown
	clearflag FLAG_SYS_NO_WHITEOUT
	release
	end

PastTown_EventScript_LassWalkBackToPosition::
	applymovement LOCALID_PASTTOWN_LASS, Common_Movement_WalkLeft
	return
	
PastTown_EventScript_LassOyGeezer::
	setflag FLAG_FOUGHT_LASS
	speakername Name_Lass
	msgbox PastTown_Text_LassOyGeezer, MSGBOX_DEFAULT
	return

PastTown_EventScript_LassAnotherRound::
	speakername Name_Lass
	msgbox PastTown_Text_LassAnotherRound, MSGBOX_DEFAULT
	return

PastTown_EventScript_BeatLass::
	speakername Name_Lass
	msgbox PastTown_Text_LassHeyNoFair, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, PastTown_Text_LookerThatWasStrange
	closemessage
	setvar VAR_CUTSCENE_STATE, 10
	clearflag FLAG_SYS_NO_WHITEOUT
	release
	end

PastTown_EventScript_WalkBackBelowTrigger::
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	clearflag FLAG_SYS_FROM_TRIGGER
	return

PastTown_EventScript_LookerPassOut::
	lockall
	speakername Name_Looker
	msgbox PastTown_Text_LookerUrgh, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
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

PastTown_EventScript_Fisherman::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_FishermanPregame
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_HELP_FISHERMAN
	switch VAR_RESULT
	case 1, PastTown_EventScript_FishermanQuestInitiate
	case 2, PastTown_EventScript_FishermanQuestActive
	case 3, PastTown_EventScript_FishermanQuestReward
	case 4, PastTown_EventScript_FishermanQuestComplete
	releaseall
	end

PastTown_EventScript_FishermanPregame::
	msgbox PastTown_Text_FishermanPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_FishermanQuestInitiate::
	speakername Name_Past_Fisherman
	msgbox PastTown_Text_FishermanFrustrated, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IsSomethingWrong
	faceplayer
	speak LOCALID_FISHERMAN, VAR_0x8005, Name_Past_Fisherman, PastTown_Text_FishermanHelp
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IdBeHappyToHelp
	speak LOCALID_FISHERMAN, VAR_0x8005, Name_Past_Fisherman, PastTown_Text_FishermanGreatWhere
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_LetMeThinkAboutThat
	startquest QUEST_HELP_FISHERMAN
	closemessage
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceUp
	release
	end

PastTown_EventScript_FishermanQuestActive::
	speak LOCALID_FISHERMAN, VAR_0x8005, Name_Past_Fisherman, PastTown_Text_FishermanHelp
	closemessage
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceUp
	release
	end

PastTown_EventScript_FishermanQuestReward::
	speak LOCALID_FISHERMAN, VAR_0x8005, Name_Past_Fisherman, PastTown_Text_FishermanRubbish
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	speak LOCALID_FISHERMAN, VAR_0x8005, Name_Past_Fisherman, PastTown_Text_FishermanReward
	multichoice 0, 6, MULTI_FISHERMAN_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, PastTown_EventScript_FishermanGiveOverqwil
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_FishermanGiveDragalge
	end

PastTown_EventScript_FishermanQuestFinish::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FISHERMAN
	setobjectxyperm LOCALID_FISHERMAN, 15, 32
	setobjectmovementtype LOCALID_FISHERMAN, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_FISHERMAN
	delay 80
	fadescreen FADE_FROM_BLACK
	completequest QUEST_HELP_FISHERMAN
	release
	end

PastTown_EventScript_FishermanQuestComplete::
	faceplayer
	speakername Name_Past_Fisherman
	msgbox PastTown_Text_FishermanComplete, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FISHERMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_Scientist::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_ScientistPregame
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_EUREKA
	switch VAR_RESULT
	case 1, PastTown_EventScript_ScientistQuestInitiate
	case 2, PastTown_EventScript_ScientistQuestActive
	case 4, PastTown_EventScript_ScientistQuestComplete
	releaseall
	end

PastTown_EventScript_ScientistPregame::
	faceplayer
	msgbox PastTown_Text_ScientistPregame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ScientistQuestInitiate::
	speakername Name_Past_Scientist
	msgbox PastTown_Text_ScientistThisWontDo, MSGBOX_DEFAULT
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WhatSeemsToBeTheProblem
	closemessage
	playse SE_PIN
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceRightExclamationMark
	waitmovement 0
	delay 60
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistAhYouPassedByHere
	closemessage
	fadescreen FADE_TO_BLACK
	delay 100
	fadescreen FADE_FROM_BLACK
	delay 60
	speakername Name_Looker
	msgbox Looker_Text_Asleep, MSGBOX_DEFAULT
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistAndThatsWhy
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PastTown_Text_LookerHuhWha
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistWhatIAmAsking
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ConsiderItDone
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistWonderful
	startquest QUEST_EUREKA
	closemessage
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ScientistQuestActive::
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistHaveYouFound
	checkitem ITEM_CELL_BATTERY
	goto_if_eq VAR_RESULT, TRUE, PastTown_EventScript_ScientistQuestReward
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_NotYet
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistUnfortunate
	closemessage
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ScientistQuestReward::
	playse SE_PIN
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistGiveToMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_HereYouGo
	removeitem ITEM_CELL_BATTERY, 1
	speakername NULL
	msgbox PastTown_Text_LookerHandedOverTheBattery, MSGBOX_DEFAULT
	speak LOCALID_PAST_SCIENTIST, VAR_0x8005, Name_Past_Scientist, PastTown_Text_ScientistReward
	multichoice 0, 6, MULTI_SCIENTIST_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, PastTown_EventScript_ScientistGiveGalvantula
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_ScientistGiveProbopass
	end

PastTown_EventScript_ScientistQuestFinish::
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	completequest QUEST_EUREKA
	release
	end

PastTown_EventScript_ScientistQuestComplete::
	faceplayer
	speakername Name_Past_Scientist
	msgbox PastTown_Text_ScientistComplete, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_SCIENTIST, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_Foreman::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_ForemanPregame
	returnqueststate QUEST_FARMLAND_INVASION_1
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_ForemanCarrotFarmInvasion
	goto_if_eq VAR_RESULT, 3, PastTown_EventScript_ForemanCarrotFarmInvasionReward
	returnqueststate QUEST_FARMLAND_INVASION_2
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_ForemanCabbageFarmInvasion
	goto_if_eq VAR_RESULT, 3, PastTown_EventScript_ForemanCabbageFarmInvasionReward
	returnqueststate QUEST_FARMLAND_INVASION_3
	switch VAR_RESULT
	case 1, PastTown_EventScript_ForemanPests3QuestActivate
	case 2, PastTown_EventScript_ForemanPests3QuestActive
	case 3, PastTown_EventScript_ForemanPests3QuestReward
	closemessage
	release
	end

PastTown_EventScript_ForemanCarrotFarmInvasion::
	msgbox PastTown_Text_ForemanCarrotFarmInvasion, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ForemanCarrotFarmInvasionReward::
	speakername Name_Foreman
	msgbox PastTown_Text_ForemanCarrotFarmInvasionReward
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end
	
PastTown_EventScript_ForemanCabbageFarmInvasion::
	msgbox PastTown_Text_ForemanCabbageFarmInvasion, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ForemanCabbageFarmInvasionReward::
	speakername Name_Foreman
	msgbox PastTown_Text_ForemanCabbageFarmInvasionReward
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ForemanPests3QuestActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_FOREMAN, VAR_0x8005, Name_Foreman, PastTown_Text_ForemanFarmInvasionDagNabbit
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThisSeemsSerious
	speak LOCALID_PAST_FOREMAN, VAR_0x8005, Name_Foreman, PastTown_Text_ForemanFarmInvasionWeCantDoThisAlone
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IWillHandleThis
	speak LOCALID_PAST_FOREMAN, VAR_0x8005, Name_Foreman, PastTown_Text_ForemanFarmInvasionForeverInYourDebt
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	startquest QUEST_FARMLAND_INVASION_3
	setvar VAR_PEST_CONTROL_COUNT, 0
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

PastTown_EventScript_ForemanPests3QuestActive::
	msgbox PastTown_Text_ForemanFarmInvasionActive, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

PastTown_EventScript_ForemanPests3QuestReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_FOREMAN, VAR_0x8005, Name_Foreman, PastTown_Text_ForemanFarmInvasionThankYou
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_GladICouldHelp
	speak LOCALID_PAST_FOREMAN, VAR_0x8005, Name_Foreman, PastTown_Text_ForemanFarmInvasionGivePokemon
	multichoice 0, 6, MULTI_FOREMAN_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, PastTown_EventScript_ForemanGiveBreloom
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_ForemanGiveShiinotic
	release
	end

PastTown_EventScript_ForemanQuestFinish::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PAST_CARROTFARMER
	removeobject LOCALID_PAST_CABBAGEFARMER
	setobjectxyperm LOCALID_PAST_CARROTFARMER, 31, 30
	setobjectxyperm LOCALID_PAST_CABBAGEFARMER, 39, 30
	setobjectmovementtype LOCALID_PAST_CARROTFARMER, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype LOCALID_PAST_CABBAGEFARMER, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	addobject LOCALID_PAST_CARROTFARMER
	addobject LOCALID_PAST_CABBAGEFARMER
	fadescreen FADE_FROM_BLACK
	completequest QUEST_FARMLAND_INVASION_3
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

PastTown_EventScript_CarrotFarmer::
	lock
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_CarrotFarmerPregame
	returnqueststate QUEST_FARMLAND_INVASION_1
	switch VAR_RESULT
	case 1, PastTown_EventScript_CarrotFarmerPests1QuestActivate
	case 2, PastTown_EventScript_CarrotFarmerPests1QuestActive
	case 3, PastTown_EventScript_CarrotFarmerPests1QuestReward
	returnqueststate QUEST_FARMLAND_INVASION_2
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_CarrotFarmerPostQuest1
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_CarrotFarmerPostQuest1Quest2Reward
	returnqueststate QUEST_FARMLAND_INVASION_3
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_FarmersPests3
	goto_if_eq VAR_RESULT, 3, PastTown_EventScript_CarrotFarmerPests3Reward
	faceplayer
	msgbox PastTown_Text_CarrotFarmerPostQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CarrotFarmerPests1QuestActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_CARROTFARMER, DIR_SOUTH, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerMyCarrots
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WhatSeemsToBeTheProblem
	faceplayer
	playse SE_PIN
	applymovement LOCALID_PAST_CARROTFARMER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_PAST_CARROTFARMER, VAR_0x8005, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerYouSeemStrong
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_LeaveItToMe
	startquest QUEST_FARMLAND_INVASION_1
	setvar VAR_PEST_CONTROL_COUNT, 0
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

PastTown_EventScript_CarrotFarmerPests1QuestActive::
	faceplayer
	msgbox PastTown_Text_CarrotFarmerMyPoorCarrots, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CarrotFarmerPests1QuestReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_CARROTFARMER, VAR_0x8005, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerMySweetCarrots
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_AllInADaysWork
	speak LOCALID_PAST_CARROTFARMER, VAR_0x8005, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerThankYouQuest1
	speakername NULL
	additem ITEM_SALAC_BERRY, 1
	additem ITEM_LIECHI_BERRY, 1
	additem ITEM_PETAYA_BERRY, 1
	playfanfare MUS_OBTAIN_ITEM
	message PastTown_Text_ObtainedBerries
	waitmessage
	waitfanfare
	completequest QUEST_FARMLAND_INVASION_1
	fadescreen FADE_TO_BLACK
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	removeobject LOCALID_PAST_CARROTFARMER
	removeobject LOCALID_PAST_CABBAGEFARMER
	clearflag FLAG_HIDE_PEST_2_1
	clearflag FLAG_HIDE_PEST_2_2
	clearflag FLAG_HIDE_PEST_2_3
	setobjectxyperm LOCALID_PAST_CARROTFARMER, 31, 30
	setobjectxyperm LOCALID_PAST_CABBAGEFARMER, 39, 27
	setobjectmovementtype LOCALID_PAST_CARROTFARMER, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype LOCALID_PAST_CABBAGEFARMER, MOVEMENT_TYPE_FACE_DOWN
	addobject LOCALID_PAST_CARROTFARMER
	addobject LOCALID_PAST_CABBAGEFARMER
	addobject LOCALID_PEST_2_1
	addobject LOCALID_PEST_2_2
	addobject LOCALID_PEST_2_3
	fadescreen FADE_FROM_BLACK
	release
	end

PastTown_EventScript_CabbageFarmer::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, PastTown_EventScript_CabbageFarmerPregame
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_FARMLAND_INVASION_1
	goto_if_lt VAR_RESULT, 3, PastTown_EventScript_CabbageFarmerPreQuest2
	goto_if_eq VAR_RESULT, 3, PastTown_EventScript_CabbageFarmerPreQuest2Quest1Reward
	returnqueststate QUEST_FARMLAND_INVASION_2
	switch VAR_RESULT
	case 1, PastTown_EventScript_CabbageFarmerPests2QuestActivate
	case 2, PastTown_EventScript_CabbageFarmerPests2QuestActive
	case 3, PastTown_EventScript_CabbageFarmerPests2QuestReward
	returnqueststate QUEST_FARMLAND_INVASION_3
	goto_if_lt VAR_RESULT, 4, PastTown_EventScript_FarmersPests3
	goto_if_eq VAR_RESULT, 3, PastTown_EventScript_CabbageFarmerPests3Reward
	faceplayer
	msgbox PastTown_Text_CabbageFarmerPostQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CabbageFarmerPests2QuestActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_CABBAGEFARMER, DIR_SOUTH, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerMyCabbages
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IsSomethingWrong
	speak LOCALID_PAST_CABBAGEFARMER, VAR_0x8005, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerYesSomethingIsWrong
	speak LOCALID_PLAYER VAR_FACING, Name_Looker, Looker_Text_ConsiderItDone
	speak LOCALID_PAST_CABBAGEFARMER, VAR_0x8005, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerAppreciated
	startquest QUEST_FARMLAND_INVASION_2
	setvar VAR_PEST_CONTROL_COUNT, 0
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

PastTown_EventScript_CabbageFarmerPests2QuestActive::
	faceplayer
	msgbox PastTown_Text_CabbageFarmerMyPoorCabbages, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CabbageFarmerPests2QuestReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_CABBAGEFARMER, VAR_0x8005, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerTheBugs
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_GladICouldHelp
	speak LOCALID_PAST_CABBAGEFARMER, VAR_0x8005, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerThankYou
	speakername NULL
	giveitem ITEM_TM_DRAGON_CLAW @ Replaced Dragon Claw with U-Turn
	completequest QUEST_FARMLAND_INVASION_2
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PAST_CARROTFARMER
	removeobject LOCALID_PAST_CABBAGEFARMER
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	clearflag FLAG_HIDE_PEST_3_1
	clearflag FLAG_HIDE_PEST_3_2
	clearflag FLAG_HIDE_PEST_3_3
	clearflag FLAG_HIDE_PEST_3_4
	clearflag FLAG_HIDE_PEST_3_5
	clearflag FLAG_HIDE_PEST_3_6
	setobjectxyperm LOCALID_PAST_CARROTFARMER, 38, 24
	setobjectxyperm LOCALID_PAST_CABBAGEFARMER, 39, 24
	setobjectmovementtype LOCALID_PAST_CARROTFARMER, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_PAST_CABBAGEFARMER, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_PAST_CARROTFARMER
	addobject LOCALID_PAST_CABBAGEFARMER
	addobject LOCALID_PEST_3_1
	addobject LOCALID_PEST_3_2
	addobject LOCALID_PEST_3_3
	addobject LOCALID_PEST_3_4
	addobject LOCALID_PEST_3_5
	addobject LOCALID_PEST_3_6
	fadescreen FADE_FROM_BLACK
	release
	end

PastTown_EventScript_FarmersPests3::
	speak LOCALID_PAST_CARROTFARMER, DIR_EAST, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerQuest3
	speak LOCALID_PAST_CABBAGEFARMER, DIR_WEST, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerQuest3
	speak LOCALID_PAST_CARROTFARMER, DIR_EAST, Name_Carrot_Farmer, PastTown_Text_CarrotFarmerQuest3IDontKnow
	speak LOCALID_PAST_CABBAGEFARMER, DIR_WEST, Name_Cabbage_Farmer, PastTown_Text_CabbageFarmerQuest3Landorus
	closemessage
	release
	end
	
PastTown_EventScript_CarrotFarmerPests3Reward::
	msgbox PastTown_Text_CarrotFarmerQuest3Reward, MSGBOX_DEFAULT
	closemessage
	release
	end
	
PastTown_EventScript_CabbageFarmerPests3Reward::
	msgbox PastTown_Text_CabbageFarmerQuest3Reward, MSGBOX_DEFAULT
	closemessage
	release
	end
	
PastTown_EventScript_CabbageFarmerPreQuest2::
	faceplayer
	speakername Name_Cabbage_Farmer
	msgbox PastTown_Text_CabbageFarmerPreQuest2, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CabbageFarmerPreQuest2Quest1Reward::
	faceplayer
	speakername Name_Cabbage_Farmer
	msgbox PastTown_Text_CabbageFarmerPreQuest2Quest1Reward, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CarrotFarmerPostQuest1::
	faceplayer
	speakername Name_Carrot_Farmer
	msgbox PastTown_Text_CarrotFarmerPostQuest1, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CarrotFarmerPostQuest1Quest2Reward::
	faceplayer
	speakername Name_Carrot_Farmer
	msgbox PastTown_Text_CarrotFarmerPostQuest1Quest2Reward, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_ForemanPregame::
	msgbox PastTown_Text_ForemanPregame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_FOREMAN, Common_Movement_FaceDown
	waitmovement 0
	release
	end
	
PastTown_EventScript_CarrotFarmerPregame::
	faceplayer
	msgbox PastTown_Text_CarrotFarmerPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CabbageFarmerPregame::
	faceplayer
	msgbox PastTown_Text_CabbageFarmerPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_Bunnelby::
	lock
	faceplayer
	playmoncry SPECIES_BUNNELBY, TRUE
	message PastTown_Text_Bunnelby
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_BUNNELBY, 48, ITEM_ORAN_BERRY, 0, NATURE_TIMID, 2
	createmon 1, 1, SPECIES_DIGGERSBY, 49, ITEM_ORAN_BERRY, 0, NATURE_BRAVE, 2
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Buneary::
	lock
	faceplayer
	playmoncry SPECIES_BUNEARY, TRUE
	message PastTown_Text_Buneary
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_LOPUNNY, 49, ITEM_ORAN_BERRY, 0, NATURE_JOLLY, 2
	createmon 1, 1, SPECIES_BUNEARY, 48, ITEM_ORAN_BERRY, 0, NATURE_NAIVE, 2
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Minun::
	lock
	faceplayer
	playmoncry SPECIES_MINUN, TRUE
	message PastTown_Text_Minun
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_MINUN, 49, ITEM_ORAN_BERRY, 0, NATURE_MODEST, 0
	createmon 1, 1, SPECIES_PLUSLE, 49, ITEM_ORAN_BERRY, 0, NATURE_TIMID, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Leavanny::
	lock
	faceplayer
	playmoncry SPECIES_LEAVANNY, TRUE
	message PastTown_Text_Leavanny
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_LEAVANNY, 51, ITEM_SITRUS_BERRY, 0, NATURE_HASTY, 2
	createmon 1, 1, SPECIES_SWADLOON, 50, ITEM_SITRUS_BERRY, 0, NATURE_RELAXED, 2
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Kricketune::
	lock
	faceplayer
	playmoncry SPECIES_KRICKETUNE, TRUE
	message PastTown_Text_Kricketune
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_KRICKETUNE, 50, ITEM_SITRUS_BERRY, 0, NATURE_QUIRKY, 0
	createmon 1, 1, SPECIES_KRICKETUNE, 50, ITEM_SITRUS_BERRY, 0, NATURE_QUIRKY, 2
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Flapple::
	lock
	faceplayer
	playmoncry SPECIES_FLAPPLE, TRUE
	message PastTown_Text_Flapple
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_FLAPPLE, 51, ITEM_SITRUS_BERRY, 0, NATURE_NAUGHTY, 1
	createmon 1, 1, SPECIES_APPLETUN, 51, ITEM_SITRUS_BERRY, 0, NATURE_LAX, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Breloom::
	lock
	faceplayer
	playmoncry SPECIES_BRELOOM, TRUE
	message PastTown_Text_Breloom
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_BRELOOM, 53, ITEM_SALAC_BERRY, 0, NATURE_ADAMANT, 0
	createmon 1, 1, SPECIES_SHROOMISH, 53, ITEM_SALAC_BERRY, 0, NATURE_LAX, 2
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Amoonguss::
	lock
	faceplayer
	playmoncry SPECIES_AMOONGUSS, TRUE
	message PastTown_Text_Amoonguss
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_AMOONGUSS, 53, ITEM_BLACK_SLUDGE, 0, NATURE_SASSY, 0
	createmon 1, 1, SPECIES_FOONGUS, 53, ITEM_STICKY_BARB, 0, NATURE_SASSY, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Shiinotic::
	lock
	faceplayer
	playmoncry SPECIES_SHIINOTIC, TRUE
	message PastTown_Text_Shiinotic
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_MORELULL, 53, ITEM_ROWAP_BERRY, 0, NATURE_SASSY, 1
	createmon 1, 1, SPECIES_SHIINOTIC, 53, ITEM_PETAYA_BERRY, 0, NATURE_SASSY, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end
	
PastTown_EventScript_Toedscruel::
	lock
	faceplayer
	playmoncry SPECIES_TOEDSCRUEL, TRUE
	message PastTown_Text_Toedscruel
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_TOEDSCRUEL, 53, ITEM_LIECHI_BERRY, 0, NATURE_SASSY, 0
	createmon 1, 1, SPECIES_TOEDSCOOL, 53, ITEM_JABOCA_BERRY, 0, NATURE_SASSY, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end
	
PastTown_EventScript_Parasect::
	lock
	faceplayer
	playmoncry SPECIES_PARASECT, TRUE
	message PastTown_Text_Parasect
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	createmon 1, 0, SPECIES_PARASECT, 53, ITEM_OCCA_BERRY, 0, NATURE_SASSY, 0
	createmon 1, 1, SPECIES_PARAS, 53, ITEM_OCCA_BERRY, 0, NATURE_SASSY, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompletePestsBattle
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	release
	end

PastTown_EventScript_Hydrapple::
	lock
	faceplayer
	goto_if_lt VAR_PEST_CONTROL_COUNT, 5, PastTown_EventScript_HydrappleWait
	playmoncry SPECIES_HYDRAPPLE, TRUE
	message PastTown_Text_HydrappleFight
	waitmessage
	waitmoncry
	getpartysize
	goto_if_eq VAR_RESULT, 1, PastTown_EventScript_NotEnoughPokemon
	setflag FLAG_SYS_NO_WHITEOUT
	setflag FLAG_SYS_DISABLE_CATCHING
	setflag FLAG_SYS_SMART_WILD_BATTLES
	createmon 1, 0, SPECIES_HYDRAPPLE, 60, ITEM_OCCA_BERRY, 0, NATURE_SASSY, 0
	createmon 1, 1, SPECIES_DIPPLIN, 58, ITEM_OCCA_BERRY, 0, NATURE_SASSY, 0
	setwilddoubleflag
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PastTown_EventScript_CompleteHydrappleBattle
	msgbox PastTown_Text_Hydrapple, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	clearflag FLAG_SYS_SMART_WILD_BATTLES
	release
	end

PastTown_EventScript_HydrappleWait::
	playmoncry SPECIES_HYDRAPPLE, FALSE
	msgbox PastTown_Text_Hydrapple, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

PastTown_EventScript_CompleteHydrappleBattle::
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	clearflag FLAG_SYS_SMART_WILD_BATTLES
	questmenu QUEST_MENU_SET_REWARD, QUEST_FARMLAND_INVASION_3
	goto Common_EventScript_RemoveStaticPokemon
	end

PastTown_EventScript_NotEnoughPokemon::
	speakername Name_Looker
	msgbox Looker_Text_IThinkINeedTwoPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_EventScript_CompletePestsBattle::
	clearflag FLAG_SYS_NO_WHITEOUT
	clearflag FLAG_SYS_DISABLE_CATCHING
	addvar VAR_PEST_CONTROL_COUNT, 1
	call_if_eq VAR_PEST_CONTROL_COUNT, 3, PastTown_EventScript_PestsQuestSetReward
	goto Common_EventScript_RemoveStaticPokemon
	end

PastTown_EventScript_PestsQuestSetReward::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_FARMLAND_INVASION_1
	call_if_eq VAR_RESULT, 2, PastTown_EventScript_Pests1QuestSetReward
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_FARMLAND_INVASION_2
	call_if_eq VAR_RESULT, 2, PastTown_EventScript_Pests2QuestSetReward
	return

PastTown_EventScript_Pests1QuestSetReward::
	questmenu QUEST_MENU_SET_REWARD, QUEST_FARMLAND_INVASION_1
	return
	
PastTown_EventScript_Pests2QuestSetReward::
	questmenu QUEST_MENU_SET_REWARD, QUEST_FARMLAND_INVASION_2
	return

PastTown_EventScript_SadGirl::
	lock
	release
	end
	
PastTown_EventScript_Wooloo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WOOLOO, CRY_MODE_NORMAL
	msgbox PastTown_Text_Wooloo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PastTown_EventScript_Mareep::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAREEP, CRY_MODE_NORMAL
	msgbox PastTown_Text_Mareep, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PastTown_EventScript_Mudsdale::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUDSDALE, CRY_MODE_NORMAL
	msgbox PastTown_Text_Mudsdale, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PastTown_Text_ForemanFarmInvasionDagNabbit:
	.string "DAGNABBIT!\p"
	.string "A raid of this level is absolutely\n"
	.string "unprecedented!\p"
	.string "Never before have this many pests\n"
	.string "decided to invade our farms at once!$"

PastTown_Text_ForemanFarmInvasionWeCantDoThisAlone:
	.string "Good sir, we cannot deal with this\n"
	.string "invasion on our own.\p"
	.string "We do not have the trainers.\p"
	.string "We do not have the resources.\p"
	.string "Please, one more time, if you could,\n"
	.string "we desperately need your help.$"

PastTown_Text_ForemanFarmInvasionForeverInYourDebt:
	.string "We shall forever be in your debt if\n"
	.string "you can clear out our farm of these\l"
	.string "festering mushroom Pokémon.$"

PastTown_Text_ForemanFarmInvasionActive:
	.string "I fear for the future if the wild\n"
	.string "Pokémon here are bold enough to\l"
	.string "attack our settlement's farms…\p"
	.string "We need a solution…$"

PastTown_Text_ForemanFarmInvasionThankYou:
	.string "We are so incredibly grateful to you,\n"
	.string "kind sir.\p"
	.string "Thank you.\p"
	.string "We do not foresee another infestation\n"
	.string "like this one coming for the rest of\l"
	.string "the season.$"

PastTown_Text_ForemanFarmInvasionGivePokemon:
	.string "Oh? It seems a couple of the pests\n"
	.string "have yet to skedaddle.\p"
	.string "We can't have them on the farm…\p"
	.string "Perhaps you could take one of them?$"

PastTown_Text_ForemanGuardDog:
	.string "We should procure a guard dog before\n"
	.string "the new year begins.\p"
	.string "Tell me, sir. Do you think Stoutland\n"
	.string "or Mabosstiff would be a better choice?$"

PastTown_Text_ForemanCarrotFarmInvasion:
	.string "Those pesky rabbits! I thought we\n"
	.string "had driven them off earlier this\l"
	.string "season!\p"
	.string "You look tough, could you please\n"
	.string "take care of them?$"

PastTown_Text_ForemanCarrotFarmInvasionReward:
	.string "Ah, that you sir for clearing out those\n"
	.string "silly rabbits!\p"
	.string "Very few trainers of your caliber live in\n"
	.string "our town, so we rely on outside help for\l"
	.string "swarms like this.\p"
	.string "'Tis a rather unreliable system… Perhaps\n"
	.string "we should explore alternatives?$"

PastTown_Text_ForemanCabbageFarmInvasion:
	.string "And now this is happening to our\n"
	.string "fine cabbages!\p"
	.string "What happened to all the predator bugs\n"
	.string "who normally feed on these pests?$"

PastTown_Text_ForemanCabbageFarmInvasionReward:
	.string "The predator bugs must be in a bust\n"
	.string "cycle at the moment…\p"
	.string "Normally we see these prey insects kept\n"
	.string "in check by local Pinsir and Scolipede…\p"
	.string "Perhaps a Pokémon of our own to guard our\n"
	.string "farms may be in our future?$"

PastTown_Text_CarrotFarmerQuest3:
	.string "Shoot…\p"
	.string "The whole harvest will be lost if\n"
	.string "nothing is done…$"
	
PastTown_Text_CabbageFarmerQuest3:
	.string "This is disastrous…\p"
	.string "Can the village survive the winter\n"
	.string "season without any produce?$"
	
PastTown_Text_CarrotFarmerQuest3IDontKnow:
	.string "I do not think so…$"

PastTown_Text_CabbageFarmerQuest3Landorus:
	.string "O great Landorus, please save our\n"
	.string "crops!$"

PastTown_Text_CarrotFarmerQuest3Reward:
	.string "My carrots… They're safe at last…$"

PastTown_Text_CabbageFarmerQuest3Reward:
	.string "My cabbages will survive!\n"
	.string "Oh thank Landorus!$"

PastTown_Text_CarrotFarmerPostQuest1:
	.string "Haha!\p"
	.string "That dingbat cabbage farmer laughed\n"
	.string "while my poor carrots were razed.\p"
	.string "But it will be me who has the last\n"
	.string "laugh when his weak, stupid produce\l"
	.string "is destroyed by bugs!$"

PastTown_Text_CarrotFarmerPostQuest1Quest2Reward:
	.string "Hmm…\p"
	.string "I SUPPOSE it is a good thing the cabbages\n"
	.string "were saved…\p"
	.string "What else are we supposed to jar ahead\n"
	.string "of the upcoming cold season?$"

PastTown_Text_CabbageFarmerPreQuest2:
	.string "Heh!\p"
	.string "That silly carrot farmer's crops are\n"
	.string "being ravaged by rabbits!\p"
	.string "Serves them right for their hatred of\n"
	.string "the mighty cabbage…$"

PastTown_Text_CabbageFarmerPreQuest2Quest1Reward:
	.string "Ahh…\p"
	.string "I submit to the idea it would have been\n"
	.string "disastrous to lose our yield of carrots…\p"
	.string "Baby carrots are the only vegetable my\n"
	.string "children will even look at…$"

PastTown_Text_ForemanPregame:
	.string "My farmhands are always fighting over\n"
	.string "the silliest things…\p"
	.string "I appreciate their dedication to their\n"
	.string "work, but they cannot cooperate for the\l"
	.string "life of them…$"

PastTown_Text_CarrotFarmerPregame:
	.string "Hmph…\p"
	.string "That other farmer has no appreciation\n"
	.string "for the value of carrots!\p"
	.string "They are vital to a person's eyesight\n"
	.string "and are superb for snacking!\p"
	.string "Much better than those bitter cabbages…$"

PastTown_Text_CabbageFarmerPregame:
	.string "Grr…\p"
	.string "That farmer over there has no respect\n"
	.string "for the mighty cabbage!\p"
	.string "Cabbages are chock-full of nutrients\n"
	.string "and sustain our whole diet!\p"
	.string "Much more valuable than those piddly\n"
	.string "little carrots…$"

PastTown_Text_CarrotFarmerMyCarrots:
	.string "No! My carrots!\p"
	.string "Rabbits are eating my darling carrots!$"

PastTown_Text_CarrotFarmerYouSeemStrong:
	.string "Oh, sir!\p"
	.string "The most horrid thing in the world is\n"
	.string "the problem!\p"
	.string "My sweet, sweet carrots are being\n"
	.string "gobbled alive by a group of dirty\l"
	.string "rodents!\p"
	.string "You look like a trainer, could you please\n"
	.string "clear out my poor carrot farm?$"

PastTown_Text_CarrotFarmerMyPoorCarrots:
	.string "My poor carrots…\p"
	.string "Raised from nothing but tiny seeds…\p"
	.string "Now food for worthless pests…$"

PastTown_Text_CarrotFarmerMySweetCarrots:
	.string "My carrots!\p"
	.string "Oh, my sweet carrots are saved!$"

PastTown_Text_CarrotFarmerThankYouQuest1:
	.string "Please accept my deepest gratitude, sir!\p"
	.string "These berries are rare. I hoped to turn\n"
	.string "them into juice, but they are superb in\l"
	.string "battles as well!$"

PastTown_Text_ObtainedBerries:
	.string "Looker obtained one Salac, Petaya, and\n"
	.string "Liechi Berry each!$"

PastTown_Text_CabbageFarmerMyCabbages:
	.string "MY CABBAGES!$"

PastTown_Text_CabbageFarmerYesSomethingIsWrong:
	.string "Of course something is wrong!\p"
	.string "Can you see with your eyes what is\n"
	.string "going on in my farm?\p"
	.string "My voluminous, leafy babies are getting\n"
	.string "turned into a bug buffet!\p"
	.string "Sir, I saw how deftly you handled the\n"
	.string "invasion of that carrot patch.\p"
	.string "Could you please help my poor cabbages?$"

PastTown_Text_CabbageFarmerAppreciated:
	.string "Oh sir, your generosity is greatly\n"
	.string "appreciated!\p"
	.string "Please, show those bugs my wrath!$"

PastTown_Text_CabbageFarmerTheBugs:
	.string "The bugs! The bugs have been driven\n"
	.string "away!\p"
	.string "Thank you, kind sir! My cabbages are sure\n"
	.string "to reach maturity now!$"

PastTown_Text_CabbageFarmerThankYou:
	.string "I committed the way those bugs scuttled\n"
	.string "off to memory.\p"
	.string "Perhaps your Pokémon could learn a thing\n"
	.string "or two from their nimble technique?$"

PastTown_Text_CabbageFarmerMyPoorCabbages:
	.string "My cabbages!\p"
	.string "My poor, crying cabbages!$"

PastTown_Text_CarrotFarmerPostQuest:
	.string "Sure, carrots may be the best food\n"
	.string "around, but at least cabbages keep us\l"
	.string "full through the winter…$"

PastTown_Text_CabbageFarmerPostQuest:
	.string "Cabbages may be the superior vegetable,\n"
	.string "but I concede that carrots are an\l"
	.string "important staple in our diet…$"

PastTown_Text_ScientistThisWontDo:
	.string "No… No…\p"
	.string "This won't do…\n"
	.string "This won't do…$"

PastTown_Text_ScientistAhYouPassedByHere:
	.string "Ah, you're the fellow who passed\n"
	.string "out at the entrance of town.\p"
	.string "My name is Sir Bartoz II.\p"
	.string "I hope you're well. Perhaps you might\n"
	.string "help with my conundrum?\p"
	.string "You see, we had been herding Wooloo in\n"
	.string "this community for quite a while.\p"
	.string "Rather fine sheep, I would say.\p"
	.string "However, some weeks ago, a shephard\n"
	.string "introduced us to a new kind of sheep -\l"
	.string "one she called Mareep.\p"
	.string "Now, this Mareep is rather peculiar…$"

PastTown_Text_ScientistAndThatsWhy:
	.string "…And that's why I come to you now,\n"
	.string "sir…\p"
	.string "Wait, have you been listening?$"

PastTown_Text_LookerHuhWha:
	.string "… … …\n"
	.string "… … …\p"
	.string "Huh? Wha…?\p"
	.string "Oh, of course I was.$"

PastTown_Text_ScientistWhatIAmAsking:
	.string "Ah, fantastic.\p"
	.string "Following my discovery that static\n"
	.string "is generated from rubbing together\l"
	.string "Mareep wool, I wish to store its\l"
	.string "power and use it to develop the city\l"
	.string "to the next level.\p"
	.string "Could you please find me such an\n"
	.string "item?$"

PastTown_Text_ScientistWonderful:
	.string "Wonderful! I look forward to seeing\n"
	.string "what you bring to me!$"

PastTown_Text_ScientistHaveYouFound:
	.string "Sir Looker, have you found the device\n"
	.string "I was asking for?\p"
	.string "I need some sort of item which can\n"
	.string "store a Mareep's static charge…$"

PastTown_Text_ScientistUnfortunate:
	.string "Unfortunate. Please let me know once\n"
	.string "you have received such an item.$"

PastTown_Text_ScientistGiveToMe:
	.string "Yes! That looks like the item!\p"
	.string "Please, give it to me!$"

PastTown_Text_LookerHandedOverTheBattery:
	.string "Looker handed the battery over to\n"
	.string "Bartoz.$"

PastTown_Text_ScientistReward:
	.string "Eureka! This is precisely the item\n"
	.string "I was looking for!\p"
	.string "What did you call this contraption?\n"
	.string "A battery?\p"
	.string "Incredible!\p"
	.string "Now we can use Mareep's wool to power\n"
	.string "our mills!\p"
	.string "No more need for all this wind energy!\p"
	.string "I had researched these other two\n"
	.string "Pokémon to no success prior.\p"
	.string "Perhaps one might assist you on your\n"
	.string "quest to save the future?\p"
	.string "Which would you prefer?$"
	
PastTown_Text_ScientistComplete:
	.string "This charged battery holds the key\n"
	.string "to the development of this city!\p"
	.string "Thank you, Sir Looker!$"

PastTown_Text_LassHeyNoFair:
	.string "What sorcery was that!?\p"
	.string "I have never seen a battler with\n"
	.string "perfect prediction skills such as\l"
	.string "yours!\p"
	.string "Old man, you must be cheating!$"

PastTown_Text_LookerThatWasStrange:
	.string "That was odd…\p"
	.string "Did I see into the future just now?$"
	
PastTown_Text_LassNobodyCanBeatMe:
	.string "Ha! There is not a soul in this\n"
	.string "town who can stand up to me!$"

PastTown_Text_LassYouCheated:
	.string "I may not know how, but you\n"
	.string "CERTAINLY cheated in our fight!\p"
	.string "Cheater!$"

PastTown_Text_LassOyGeezer:
	.string "Oy, geezer!\p"
	.string "You must be an outsider to our\n"
	.string "village!\p"
	.string "Know this, there is nobody\n"
	.string "in this village stronger than\l"
	.string "I in Pokémon battles!\p"
	.string "If you wish to pass through to\n"
	.string "the Shrine of Prosperity, then\l"
	.string "show me your strength!$"

PastTown_Text_LassAnotherRound:
	.string "Are you ready for another round,\n"
	.string "old man?\p"
	.string "Let's fight!$"

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

PastTown_Text_LassLoss:
	.string "Impossible!\n"
	.string "It was like you knew my every move!$"

PastTown_Text_FishermanFrustrated:
	.string "Grrr…\p"
	.string "Nothing's biting…\p"
	.string "There must be somewhere in town\n"
	.string "where I can catch some proper fish…$"

PastTown_Text_FishermanHelp:
	.string "Sir, have you an idea as to where\n"
	.string "the best place to fish might be?\p"
	.string "This spot is bearing no fruit!$"

PastTown_Text_FishermanGreatWhere:
	.string "Great! So where might I find a good\n"
	.string "fishing spot then?$"

PastTown_Text_FishermanRubbish:
	.string "Huh? What is this rubbish about a\n"
	.string "Wailord and rotting carcasses?$"

PastTown_Text_FishermanReward:
	.string "Ah! So the fish breed closer to the\n"
	.string "mouth of the river than the riverbank?\p"
	.string "Thank you, stranger.\p"
	.string "Here, take one of these Pokémon.\p"
	.string "This spot yeilds nothing but poisonous\n"
	.string "marine life…$"

PastTown_Text_FishermanComplete:
	.string "Whoa, this fishing spot is incredible!\p"
	.string "Thank you!$"

PastTown_Text_FishermanPregame:
	.string "Grrr…\p"
	.string "Nothing's biting…$"

PastTown_Text_ScientistPregame:
	.string "Huh? You seem to be new here…\p"
	.string "Are you, perchance, another traveler\n"
	.string "from the…\p"
	.string "No… Impossible…\p"
	.string "We never have this many at once…$"

PastTown_Text_Bunnelby:
	.string "Bun?$"

PastTown_Text_Buneary:
	.string "Nrrr!$"

PastTown_Text_Minun:
	.string "Mraaa!$"

PastTown_Text_Leavanny:
	.string "Vaaaaaaan!"

PastTown_Text_Kricketune:
	.string "Delelelelele!$"

PastTown_Text_Flapple:
	.string "(flapping noises)$"

PastTown_Text_Parasect:
	.string "Ssssssec…$"

PastTown_Text_Breloom:
	.string "Raaaaa?$"

PastTown_Text_Amoonguss:
	.string "Moooooooo!$"

PastTown_Text_Shiinotic:
	.string "Shshshshshsh…$"

PastTown_Text_Toedscruel:
	.string "Ooooooooo…$"

PastTown_Text_Hydrapple:
	.string "Ssssssss…\p"
	.string "(Hydrapple is watching\n"
	.string "carefully…)$"

PastTown_Text_HydrappleFight:
	.string "Hssssss!$"

PastTown_Text_Wooloo:
	.string "Baaa!$"

PastTown_Text_Mareep:
	.string "Maaa!$"

PastTown_Text_Mudsdale:
	.string "Nyehehehehehe!$"

PastTown_Text_TownHallSign:
	.string "Porta Bella Town Hall\p"
	.string "Open to all weary travelers or those\n"
	.string "looking for a drink!$"
	
PastTown_Text_TrainerTips:
	.string "Trainer Tips:\p"
	.string "Celebi's time travel powers have\n"
	.string "rubbed off on Looker, so now he can\l"
	.string "see the future!\p"
	.string "In battle, press L to see the next turn\n"
	.string "of the opponent's left Pokémon, and R to\l"
	.string "see the turn of the right Pokémon!$"