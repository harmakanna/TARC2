PresentTown_Port_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PresentTown_Port_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PresentTown_Port_OnFrame
	.byte 0

PresentTown_Port_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 0, PresentTown_Port_SetUpArrival
	end

PresentTown_Port_SetUpArrival::
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 16, 7
	setobjectxy LOCALID_PORT_SHIP, 3, 9
	return

PresentTown_Port_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 0, PresentTown_Port_EventScript_Arrival
	.2byte 0

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
	setvar VAR_CUTSCENE_STATE, 1
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
	setvar VAR_CUTSCENE_STATE, 2
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManYouWantAMagikarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerNotInterested
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManYouSure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerPositive
	applymovement LOCALID_PORT_MAGIKARPMAN, Common_Movement_WalkInPlaceFasterRight
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManOhFine, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 17, PresentTown_Port_EventScript_LookerStepAside
	call_if_eq VAR_TEMP_0, 18, PresentTown_Port_EventScript_MagikarpManWalkToBench
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 21, 8
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_LEFT
	releaseall
	end
	
PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromTrigger::
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, PresentTown_Port_Text_LookerSupportLocalBusiness
	speak LOCALID_PORT_MAGIKARPMAN, DIR_EAST, Name_Magikarp_Man, PresentTown_Port_Text_MagikarpManRememberNoTakebacks
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MAGIKARP
    givemonwithot OT_LOOKER_MAGIKARP
	speakername NULL
	call PresentTown_Port_EventScript_ReceivedMagikarpFanfare
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 17, PresentTown_Port_EventScript_LookerStepAside
	call_if_eq VAR_TEMP_0, 18, PresentTown_Port_EventScript_MagikarpManWalkToBench
	setobjectxyperm LOCALID_PORT_MAGIKARPMAN, 21, 8
	setobjectmovementtype LOCALID_PORT_MAGIKARPMAN, MOVEMENT_TYPE_FACE_LEFT
	releaseall
	end

PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromBench::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerSupportLocalBusiness
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
	speak LOCALID_PORT_MAGIKARPMAN, VAR_0x8005, Name_Magikarp_Man, PresentTown_Port_Text_MagikarpManRememberNoTakebacks
	release
	end

PresentTown_Port_EventScript_MagikarpManWalkToBench::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_PORT_MAGIKARPMAN, PresentTown_Port_Movement_MagikarpManWalkToBench
	waitmovement 0
	return

PresentTown_Port_EventScript_MagikarpMan::
	lock
	faceplayer
	goto_if_set FLAG_PURCHASED_MAGIKARP, PresentTown_Port_EventScript_MagikarpManNoTakebacks
	call Script_GetNPCFacingDirection
	speakername Name_Magikarp_Man
	msgbox PresentTown_Port_Text_MagikarpManYouSureYouDontWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PresentTown_Port_EventScript_MagikarpManGivesMagikarpFromBench
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, PresentTown_Port_Text_LookerNotInterested
	closemessage
	release
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

PresentTown_Port_Text_MagikarpManYouSureYouDontWant:
	.string "You suuuuuuure you don't want a\n$"
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