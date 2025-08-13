PastTown_Port_MapScripts::
	.byte 0


PastTown_Port_EventScript_WingFossil::
	lockall
	msgbox PastTown_Port_Text_TakeWingFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PastTown_Port_EventScript_LeaveWingFossil
	giveitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_WING_FOSSIL
	removeobject LOCALID_WING_FOSSIL
	delay 30
	setflag FLAG_CHOSE_WING_FOSSIL
	goto PastTown_Port_EventScript_PokemaniacChoosesTuskFossil
	end

PastTown_Port_EventScript_LeaveWingFossil::
	msgbox PastTown_Port_Text_LeftWingFossilAlone, MSGBOX_DEFAULT
	release
	end

PastTown_Port_EventScript_TuskFossil::
	lockall
	faceplayer
	msgbox PastTown_Port_Text_TakeTuskFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PastTown_Port_EventScript_LeaveTuskFossil
	giveitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_TUSK_FOSSIL
	removeobject LOCALID_TUSK_FOSSIL
	delay 30
	setflag FLAG_CHOSE_TUSK_FOSSIL
	goto PastTown_Port_EventScript_PokemaniacChoosesWingFossil
	end

PastTown_Port_EventScript_LeaveTuskFossil::
	msgbox PastTown_Port_Text_LeftTuskFossilAlone, MSGBOX_DEFAULT
	release
	end

PastTown_Port_ManiacTrigger1::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer1
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 18, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end

PastTown_Port_ManiacTrigger2::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer1
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 19, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end
	
PastTown_Port_ManiacTrigger3::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer1
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 20, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end
	
PastTown_Port_ManiacTrigger4::
	lockall
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	playse SE_PIN
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, Common_Movement_FaceDownExclamationMark
	message PastTown_Port_Text_ManiacNo
	waitmessage
	delay 80
	closemessage
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movement_PokemaniacToPlayer1
	waitmovement 0
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 21, 19
	goto PastTown_Port_EventScript_TriggerPokemaniacFight
	end

PastTown_Port_Movement_PokemaniacToPlayer1:
	walk_left
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer2:
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer3:
	walk_right
	walk_down
	walk_down
	step_end

PastTown_Port_Movement_PokemaniacToPlayer4:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

PastTown_Port_EventScript_TriggerPokemaniacFight::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacDoNotApproachThoseFossils, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EVERETT, PastTown_Port_Text_EverettDefeated
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacOhFine, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

PastTown_Port_EventScript_PokemaniacChoosesTuskFossil::
	getobjectcurrentxy LOCALID_PASTTOWN_PORT_MANIAC, CURRENT_POSITION, VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 18, PastTown_Port_EventScript_PokemaniacMovesToTusk1
	call_if_eq VAR_0x8000, 19, PastTown_Port_EventScript_PokemaniacMovesToTusk2
	call_if_eq VAR_0x8000, 20, PastTown_Port_EventScript_PokemaniacMovesToTusk3
	call_if_eq VAR_0x8000, 21, PastTown_Port_EventScript_PokemaniacMovesToTusk4
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_PokemaniacIllChooseTusk, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_TUSK_FOSSIL
	removeobject LOCALID_TUSK_FOSSIL
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 18, 19
	goto PastTown_Port_EventScript_FinishFossilSelection
	end

PastTown_Port_EventScript_PokemaniacMovesToTusk1::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk1
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk1:
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk2::
	call_if_eq VAR_0x8001, 16, PastTown_Port_EventScript_PokemaniacMovesToTuskFromTop
	call_if_eq VAR_0x8001, 19, PastTown_Port_EventScript_PokemaniacMovesToTuskFromLow
	return

PastTown_Port_EventScript_PokemaniacMovesToTuskFromTop::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk2Top
	waitmovement 0
	return

PastTown_Port_EventScript_PokemaniacMovesToTuskFromLow::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk2Low
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk2Low:
	walk_down
	walk_left
	step_end

PastTown_Port_Movemenet_PokemaniacToTusk2Top:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk3::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk3
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk3:
	walk_left
	walk_left
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacMovesToTusk4::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToTusk4
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToTusk4:
	walk_left
	walk_left
	walk_left
	walk_down
	face_left
	step_end

PastTown_Port_EventScript_PokemaniacChoosesWingFossil::
	getobjectcurrentxy LOCALID_PASTTOWN_PORT_MANIAC, CURRENT_POSITION, VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 18, PastTown_Port_EventScript_PokemaniacMovesToWing1
	call_if_eq VAR_0x8000, 19, PastTown_Port_EventScript_PokemaniacMovesToWing2
	call_if_eq VAR_0x8000, 20, PastTown_Port_EventScript_PokemaniacMovesToWing3
	call_if_eq VAR_0x8000, 21, PastTown_Port_EventScript_PokemaniacMovesToWing4
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_PokemaniacIllChooseWing, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_WING_FOSSIL
	removeobject LOCALID_WING_FOSSIL
	setobjectxyperm LOCALID_PASTTOWN_PORT_MANIAC, 21, 19
	goto PastTown_Port_EventScript_FinishFossilSelection
	end

PastTown_Port_EventScript_PokemaniacMovesToWing1::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing1
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing1:
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing2::
	call_if_eq VAR_0x8001, 16, PastTown_Port_EventScript_PokemaniacMovesToWingFromTop
	call_if_eq VAR_0x8001, 19, PastTown_Port_EventScript_PokemaniacMovesToWingFromLow
	return

PastTown_Port_EventScript_PokemaniacMovesToWingFromTop::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing2Top
	waitmovement 0
	return

PastTown_Port_EventScript_PokemaniacMovesToWingFromLow::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing2Low
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing2Low:
	walk_right
	walk_right
	walk_left
	step_end

PastTown_Port_Movemenet_PokemaniacToWing2Top:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing3::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing3
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing3:
	walk_right
	walk_down
	step_end

PastTown_Port_EventScript_PokemaniacMovesToWing4::
	applymovement LOCALID_PASTTOWN_PORT_MANIAC, PastTown_Port_Movemenet_PokemaniacToWing4
	waitmovement 0
	return

PastTown_Port_Movemenet_PokemaniacToWing4:
	walk_down
	step_end


PastTown_Port_EventScript_FinishFossilSelection::
	speakername Name_Looker
	msgbox PastTown_Port_Text_LookerFossilRevive, MSGBOX_DEFAULT
	closemessage
	delay 60
	startquest QUEST_FORGOTTEN_TO_TIME
	closemessage
	releaseall
	end
	
PastTown_Port_EventScript_Pokemaniac::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_TUSK_FOSSIL, PastTown_Port_EventScript_PokemaniacChoseTuskFossil
	goto_if_set FLAG_CHOSE_WING_FOSSIL, PastTown_Port_EventScript_PokemaniacChoseWingFossil
	goto_if_set FLAG_SYS_MAIN_GAME_START, PastTown_Port_EventScript_PokemaniacOhFossils
	msgbox PastTown_Port_Text_ManiacLookingForFossils, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacOhFossils::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacOhFossils, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacChoseWingFossil::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacChoseTuskFossil, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_EventScript_PokemaniacChoseTuskFossil::
	speakername Name_Past_Maniac
	msgbox PastTown_Port_Text_ManiacChoseWingFossil, MSGBOX_DEFAULT
	closemessage
	release
	end

PastTown_Port_Text_LookerFossilRevive:
	.string "Hmm…\p"
	.string "I wonder what I could do with this\n"
	.string "fossil…$"

PastTown_Port_Text_ManiacNo:
	.string "No!$"

PastTown_Port_Text_ManiacDoNotApproachThoseFossils:
	.string "I have been waiting months for new\n"
	.string "fossils to appear on the shores of\l"
	.string "this river delta bay!\p"
	.string "I arrived first, so I claim those\n"
	.string "two fossils, even if I must battle for!$"

PastTown_Port_Text_EverettDefeated:
	.string "No…\n"
	.string "I had been waiting for so long too…$"

PastTown_Port_Text_ManiacOhFine:
	.string "Oh fine…\p"
	.string "You may have a fossil…\p"
	.string "But please, do not take both…$"

PastTown_Port_Text_ManiacLookingForFossils:
	.string "Oh river delta…\p"
	.string "When will you bestow upon me\n"
	.string "the gift of a fossil?\p"
	.string "I have strolled your shores for months\n"
	.string "with no reward…$"

PastTown_Port_Text_ManiacOhFossils:
	.string "Oh great river delta!\p"
	.string "Thank you for bestowing upon me not\n"
	.string "one, but two fossils today!$"

PastTown_Port_Text_PokemaniacIllChooseTusk:
	.string "In that case, I shall study the\n"
	.string "eroded tusk!$"

PastTown_Port_Text_PokemaniacIllChooseWing:
	.string "In that case, I shall study the\n"
	.string "wing imprint!$"

PastTown_Port_Text_ManiacChoseTuskFossil:
	.string "This tusk fossil is fascinating!\p"
	.string "Despite being seemingly thousands\n"
	.string "of years old, the ivory remains as\l"
	.string "sturdy as an Aggron!\p"
	.string "Truly, it was the better fossil!$"

PastTown_Port_Text_ManiacChoseWingFossil:
	.string "This wing fossil is sublime!\p"
	.string "Despite being seemingly thousands\n"
	.string "of years old, the wing's sheen has\l"
	.string "stayed as radiant as a Gholdengo!\p"
	.string "Truly, it was the better fossil!$"

PastTown_Port_Text_TakeTuskFossil:
	.string "Looker took the eroded tooth!$"

PastTown_Port_Text_TakeWingFossil:
	.string "Looker took the wing imprint!$"

PastTown_Port_Text_LeftTuskFossilAlone:
	.string "Looker left the eroded tooth alone.$"

PastTown_Port_Text_LeftWingFossilAlone:
	.string "Looker left the wing imprint alone.$"