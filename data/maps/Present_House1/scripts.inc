Present_House1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_House1_OnTransition
	.byte 0

Present_House1_OnTransition:
	returnqueststate QUEST_HOMEGROWN_REMEDIES
	call_if_eq VAR_RESULT, 4, Present_House1_EventScript_PlaceAilingMan
	end

Present_House1_EventScript_PlaceAilingMan:
	setobjectxyperm LOCALID_PRESENT_SICK_MAN, 8, 5
	setobjectmovementtype LOCALID_PRESENT_SICK_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return
	
Present_House1_EventScript_AilingMan::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_House1_EventScript_AilingManPregame
	returnqueststate QUEST_HOMEGROWN_REMEDIES
	switch VAR_RESULT
	case 1, Present_House1_EventScript_AilingManQuestActivate 
	case 2, Present_House1_EventScript_AilingManQuestActive
	case 3, Present_House1_EventScript_AilingManQuestReward
	case 4, Present_House1_EventScript_AilingManQuestComplete
	release
	end

Present_House1_EventScript_AilingManQuestActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PRESENT_SICK_MAN, DIR_SOUTH, Name_Sick_Man, Present_House1_Text_AilingManPregame
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WhatSeemsToBeTheProblem
	speak LOCALID_PRESENT_SICK_MAN, DIR_SOUTH, Name_Sick_Man, Present_House1_Text_AilingManMyTimeIsUp
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThereHasToBeSomething
	speak LOCALID_PRESENT_SICK_MAN, DIR_SOUTH, Name_Sick_Man, Present_House1_Text_AilingManAnAncientHerb
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IWillHandleThis
	speak LOCALID_PRESENT_SICK_MAN, DIR_SOUTH, Name_Sick_Man, Present_House1_Text_AilingManGroan
	startquest QUEST_HOMEGROWN_REMEDIES
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_House1_EventScript_AilingManQuestActive::
	speakername Name_Sick_Man
	msgbox Present_House1_Text_AilingManGroan
	closemessage
	release
	end

Present_House1_EventScript_AilingManQuestReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IFoundWhatYoureLookingFor
	speak LOCALID_PRESENT_SICK_MAN, DIR_SOUTH, Name_Sick_Man, Present_House1_Text_AilingManPleaseGiveIt
	call Script_GetNPCFacingDirection
	speakername NULL
	removeitem ITEM_REVIVAL_HERB
	playfanfare MUS_OBTAIN_TMHM
	message Present_House1_Text_LookerHandedOverRevivalHerb
	waitmessage
	waitfanfare
	closemessage
	getplayerxy VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 13, Present_House1_EventScript_AilingManMoveRight
	call_if_eq VAR_0x8000, 15, Present_House1_EventScript_AilingManMoveLeft
	speak LOCALID_PRESENT_SICK_MAN, VAR_0x8005, Name_Well_Man, Present_House1_Text_AilingManFeelingBetter
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_GladICouldHelp
	speak LOCALID_PRESENT_SICK_MAN, VAR_0x8005, Name_Well_Man, Present_House1_Text_AilingManCanTeachMoves
	completequest QUEST_HOMEGROWN_REMEDIES
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_House1_EventScript_AilingManMoveRight::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	waitmovement 0
	delay 30
	speakername Name_Sick_Man
	msgbox Present_House1_Text_AilingManMoving, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_CAMERA, Present_House1_Movement_AilingManMoveRight
	applymovement LOCALID_PRESENT_SICK_MAN, Present_House1_Movement_AilingManMoveRight
	waitmovement 0
	speak LOCALID_PRESENT_SICK_MAN, DIR_NORTH, Name_Well_Man, Present_House1_Text_AilingManIDidIt
	closemessage
	delay 10
	applymovement LOCALID_CAMERA, Present_House1_Movement_MoveCameraBackToPlayerOnLeft
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_PLAYER, Present_House1_Movement_PlayerWalkToAilingManFromLeft
	waitmovement 0
	return

Present_House1_Movement_AilingManMoveRight:
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_left
	walk_slow_down
	walk_slow_down
	step_end

Present_House1_Movement_MoveCameraBackToPlayerOnLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

Present_House1_Movement_PlayerWalkToAilingManFromLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Present_House1_EventScript_AilingManMoveLeft::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	waitmovement 0
	delay 30
	speakername Name_Sick_Man
	msgbox Present_House1_Text_AilingManMoving, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_CAMERA, Present_House1_Movement_AilingManMoveLeft
	applymovement LOCALID_PRESENT_SICK_MAN, Present_House1_Movement_AilingManMoveLeft
	waitmovement 0
	speak LOCALID_PRESENT_SICK_MAN, DIR_NORTH, Name_Well_Man, Present_House1_Text_AilingManIDidIt
	closemessage
	delay 10
	applymovement LOCALID_CAMERA, Present_House1_Movement_MoveCameraBackToPlayerOnRight
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_PLAYER, Present_House1_Movement_PlayerWalkToAilingManFromRight
	waitmovement 0
	return
	
Present_House1_Movement_AilingManMoveLeft:
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	step_end

Present_House1_Movement_MoveCameraBackToPlayerOnRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
	
Present_House1_Movement_PlayerWalkToAilingManFromRight:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end
	
Present_House1_EventScript_AilingManQuestComplete::
	faceplayer
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManCanTeachMoves, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Present_House1_EventScript_AilingManEndLearnMove
	goto Present_House1_EventScript_AilingManChooseMon
	end

Present_House1_EventScript_AilingManChooseMon::
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Present_House1_EventScript_AilingManEndLearnMove
	goto_if_eq VAR_0x8005, 0, Present_House1_EventScript_AilingManNoMoveToTeachMon
	goto Present_House1_EventScript_AilingManChooseMove
	end

Present_House1_EventScript_AilingManChooseMove::
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManTeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, Present_House1_EventScript_AilingManChooseMon
	goto Present_House1_EventScript_AilingManEndLearnMove
	end

Present_House1_EventScript_AilingManNoMoveToTeachMon::
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManCantTeachMove, MSGBOX_DEFAULT
	goto Present_House1_EventScript_AilingManChooseMon
	end

Present_House1_EventScript_AilingManEndLearnMove::
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManLetMeKnow, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Present_House1_EventScript_AilingManPregame::
	speakername Name_Well_Man
	msgbox Present_House1_Text_AilingManPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_House1_EventScript_FatMan::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	speak LOCALID_HOUSE_FATMAN, VAR_0x8005, Name_Fat_Man Present_House1_Text_FatMan
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_House1_Text_LookerDontWantTo
	speak LOCALID_HOUSE_FATMAN, VAR_0x8005, Name_Fat_Man Present_House1_Text_FatManOkay
	closemessage
	release
	end

Present_House1_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox Present_House1_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_House1_Text_FatMan:
	.string "Huh… I've seen you around town, and\n"
	.string "I've been wondering.\p"
	.string "Why do you powerwalk everywhere?$"

Present_House1_Text_LookerDontWantTo:
	.string "As a professional representing the\n"
	.string "International Police, I must be sure to\l"
	.string "maintain my demeanor and look my best at\l"
	.string "all times!$"

Present_House1_Text_FatManOkay:
	.string "Oh, okay.\p"
	.string "Weird.$"

Present_House1_Text_Snubbull:
	.string "Snub-bu-bull.$"

Present_House1_Text_AilingManPregame:
	.string "Uwooooooooo…\p"
	.string "My boooooooones…$"

Present_House1_Text_AilingManMyTimeIsUp:
	.string "Ohhhh… I think my time is up…\p"
	.string "I don't think I can make it to the end\n"
	.string "of the month…\p"
	.string "I have no regrets…$"

Present_House1_Text_AilingManAnAncientHerb:
	.string "Mmmmmm… Maybe that could work…\p"
	.string "When I was a young'un, my great-gramma\n"
	.string "cooked with this one herb to keep\l"
	.string "herself lively and strong…\p"
	.string "But I haven't seen that herb around here\n"
	.string "in a looooooong time…\p"
	.string "Forget it…\n"
	.string "I suppose nothing can help me…$"

Present_House1_Text_AilingManGroan:
	.string "Oooooh…$"

Present_House1_Text_AilingManPleaseGiveIt:
	.string "You found it…?\p"
	.string "If you could, may I please have it…?$"

Present_House1_Text_AilingManMoving:
	.string "Ohh…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Ohh…?\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Ohh!$"

Present_House1_Text_AilingManIDidIt:
	.string "Oh my!\p"
	.string "I can move!$"

Present_House1_Text_AilingManFeelingBetter:
	.string "This root is incredible! I feel three\n"
	.string "years younger now! Thank you!\p"

Present_House1_Text_AilingManCanTeachMoves:
	.string "I may not look the part, but back in\n"
	.string "my youth I was quite the trainer!\p"
	.string "If you'd like, I can teach your\n"
	.string "POKéMON some new moves.$"

Present_House1_Text_AilingManWhichMon:
	.string "Which POKéMON would you like me to teach\n"
	.string "moves to?$"
	
Present_House1_Text_AilingManCantTeachMove:
	.string "That POKéMON does not have any moves I\n"
	.string "can teach it!\p"
	.string "Please choose a different POKéMON.$"

Present_House1_Text_AilingManTeachWhichMove:
	.string "Which move should I teach?$"

Present_House1_Text_AilingManLetMeKnow:
	.string "Okay. Let me know if you would like a\n"
	.string "POKéMON to learn something new.$"

Present_House1_Text_LookerHandedOverRevivalHerb:
	.string "Looker handed over the\n"
	.string "Revival Herb!$"