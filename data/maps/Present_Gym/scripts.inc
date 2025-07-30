Present_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Gym_OnTransition
	.byte 0

Present_Gym_OnTransition:
	call_if_unset FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_ResetTrainers
	end

Present_Gym_EventScript_ResetTrainers::
	return

Present_Gym_OnFrame:
	map_script_2 VAR_PRESENT_GYM_STATE, 0, Present_Gym_EventScript_GuyPushesYouOut
	map_script_2 VAR_PRESENT_GYM_STATE, 1, Present_Gym_EventScript_GuyIntroducesQuest
	.2byte 0

Present_Gym_EventScript_Phoebe::
	lockall
	faceplayer
	call Script_GetNPCFacingDirection
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_PhoebePostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	@speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeHiLooker
	@speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerImHereOnOfficialBusiness
	@speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeIHeardYouWanted
	@speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerCorrect
	@speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeCouldWePleaseFight
	trainerbattle_no_intro TRAINER_PHOEBE, Present_Gym_Text_PhoebeDefeat
	goto Present_Gym_EventScript_PhoebeDefeated
	end

Present_Gym_EventScript_PhoebePostBattleSpeech::
	msgbox Present_Gym_Text_PhoebePostBattleSpeech, MSGBOX_DEFAULT
	releaseall
	end

Present_Gym_EventScript_PhoebeDefeated::
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	msgbox Present_Gym_Text_PhoebePostBattleSpeech, MSGBOX_DEFAULT
	completequest QUEST_DEFEAT_PHOEBE
	releaseall
	end

Present_Gym_EventScript_GymGuide::
	lockall
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_GymGuyBeatPhoebe
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_GymGuyJustKnowRepeat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Present_Gym_EventScript_GymGuyHealsYou
	msgbox Present_Gym_Text_GymGuyGoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Present_Gym_EventScript_GymGuyHealsYou::
	closemessage
	playse SE_USE_ITEM
	delay 40
	special HealPlayerParty
	call Present_Gym_EventScript_ResetTrainers
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_GymGuyGoodLuck, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Present_Gym_EventScript_GymGuyBeatPhoebe::
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_GymGuyBeatPhoebe, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
	
Present_Gym_EventScript_GuyIntroducesQuest::
	lockall
	playse SE_PIN
	applymovement LOCALID_GYM_GUY, Present_Gym_Movement_GymGuyWalksToPlayer
	waitmovement 0
	call_if_set FLAG_ENTERED_GYM_IN_INTRO, Present_Gym_EventScript_GuyRecognizesYou
	call_if_unset FLAG_ENTERED_GYM_IN_INTRO, Present_Gym_EventScript_GuyDoesntRecognizeYou
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerSoSheWantsAChangeOfPace
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_GymGuyGreatJustKnow
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerSure
	closemessage
	startquest QUEST_DEFEAT_PHOEBE
	applymovement LOCALID_GYM_GUY, Present_Gym_Movement_GymGuyWalksBackToStartingPosition
	waitmovement 0
	setvar VAR_PRESENT_GYM_STATE, 2
	releaseall
	end

Present_Gym_EventScript_GuyRecognizesYou::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerIAmBack
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_GymGuyYouWereHereEarlier
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerWonderfulCanSheComeUp
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_GymGuyNoCanDo
	return

Present_Gym_EventScript_GuyDoesntRecognizeYou::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerHello
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_GymGuyIveHeardOfYou
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerWonderfulCanSheComeUp
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_GymGuyNoCanDoInTown
	return

Present_Gym_EventScript_GuyPushesYouOut::
	lockall
	playse SE_PIN
	applymovement LOCALID_GYM_GUY, Present_Gym_Movement_GymGuyWalksToPlayer
	waitmovement 0
	goto_if_unset FLAG_ENTERED_GYM_IN_INTRO, Present_Gym_EventScript_LookerMeetsGuyPregame
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_TheresAChallenger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	fadescreen FADE_TO_BLACK
	warp MAP_PRESENT_TOWN, 55, 18
	releaseall
	end

Present_Gym_EventScript_LookerMeetsGuyPregame::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerHelloPregame
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_TheresAChallenger
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerUnderstandable
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	fadescreen FADE_TO_BLACK
	setflag FLAG_ENTERED_GYM_IN_INTRO
	warp MAP_PRESENT_TOWN, 55, 18
	releaseall
	end

Present_Gym_Movement_GymGuyWalksToPlayer:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

Present_Gym_Movement_GymGuyWalksBackToStartingPosition:
	walk_up
	walk_up
	walk_left
	face_down
	step_end

Present_Gym_EventScript_GymStatue::
	msgbox Present_Gym_Text_GymStatue, MSGBOX_SIGN
	end


Present_Gym_Text_PhoebeIntroSpeech:
	.string "Ahahaha!\p"
	.string "I'm PHOEBE of the ELITE FOUR.\n"
	.string "I did my training on MT. PYRE.\p"
	.string "While I trained, I gained the ability\n"
	.string "to commune with GHOST-type POKéMON.\p"
	.string "Yes, the bond I developed with POKéMON\n"
	.string "is extremely tight.\p"
	.string "So, come on, just try and see if you can\n"
	.string "even inflict damage on my POKéMON!$"

Present_Gym_Text_PhoebeDefeat:
	.string "Now that's the Looker I know!$"

Present_Gym_Text_PhoebePostBattleSpeech:
	.string "Hoo, I haven't had a battle like that\n"
	.string "since I retired from the Elite Four!\p"
	.string "Thanks, Looker!$"

Present_Gym_Text_GymGuyBeatPhoebe:
	.string "Dang, good stuff beating Phoebe!\p"
	.string "She's the toughest trainer around!$"

Present_Gym_Text_GymGuyGoodLuck:
	.string "All right, good luck out there!$"

Present_Gym_Text_LookerIAmBack:
	.string "Hello, I am back. I hope there\n"
	.string "isn't a gym challenger around this time?\p"
	.string "I am here on official business to discuss\n"
	.string "the most recent torrent with the leader.\p"
	.string "Would she have time now?$"

Present_Gym_Text_GymGuyYouWereHereEarlier:
	.string "Ah, Looker! I remember you\n"
	.string "came by here earlier.\p"
	.string "The gym leader is, in fact, available\n"
	.string "to speak now!$"

Present_Gym_Text_GymGuyIveHeardOfYou:
	.string "Hello, Looker! I'm so glad to\n"
	.string "meet you - I'm a big fan.\p"
	.string "The gym leader isn't taking any challengers\n"
	.string "now, so you should be able to talk to her.$"

Present_Gym_Text_LookerWonderfulCanSheComeUp:
	.string "Wonderful. Could she come up to\n"
	.string "the front so we can talk?$"

Present_Gym_Text_GymGuyNoCanDoInTown:
	.string "No can do. She heard you were\n"
	.string "in the city and said she wanted to see what\l"
	.string "you're made of if you swung by, so you\l"
	.string "gotta do the whole gym challenge.\p"
	.string "Being a leader, she rarely gets the chance\n"
	.string "to battle adults.\p"
	.string "Only kids really take the gyms seriously.$"

Present_Gym_Text_GymGuyNoCanDo:
	.string "No can do. I told her you\n"
	.string "swung by earlier and she said she wanted\l"
	.string "to see what you're made of, so you gotta\l"
	.string "do the whole gym challenge.\p"
	.string "Being a leader, she rarely gets the chance\n"
	.string "to battle adults.\p"
	.string "Only kids really take the gyms seriously.$"

Present_Gym_Text_LookerSoSheWantsAChangeOfPace:
	.string "So she wants a change of\n"
	.string "pace compared to her normal job?\p"
	.string "I have some time to indulge.$"

Present_Gym_Text_GymGuyGreatJustKnow:
	.string "Great! Just so you know, if\n"
	.string "you beat any gym trainers here but leave\l"
	.string "the gym, you will have to re-fight them!\p"
	.string "The gym leader wants to see how tough a\n"
	.string "member of the police like yourself is.$"

Present_Gym_Text_LookerSure:
	.string "Sure. It's been too long since\n"
	.string "I did a gym challenge. This should be\l"
	.string "a fun change of pace.$"

Present_Gym_Text_GymGuyJustKnowRepeat:
	.string "Just so you know, if you\n"
	.string "leave the gym or get healed by me, you\l"
	.string "will have to re-fight the gym trainers!\p"
	.string "Knowing that, would you like a heal?$"

Present_Gym_Text_LookerHello:
	.string "Hello. My name is Looker with the\n"
	.string "International Police.\p"
	.string "I am here to ask the gym leader about the\n"
	.string "most recent downpour?\p"
	.string "I am here on official business and would\n"
	.string "appreciate an audience with her soon.$"

Present_Gym_Text_LookerHelloPregame:
	.string "Hello. My name is Looker with the\n"
	.string "International Police.\p"
	.string "I am here to ask the gym leader about the\n"
	.string "recent activities of Team Aqua?\p"
	.string "I am here on official business and would\n"
	.string "appreciate an audience with her.$"

Present_Gym_Text_TheresAChallenger:
	.string "Hello, Looker! Sorry, but a\n"
	.string "trainer is currently challenging the gym.\p"
	.string "You will have to come back later once the\n"
	.string "gym is cleared.$"

Present_Gym_Text_LookerUnderstandable:
	.string "Oh, that's unfortunate.\n"
	.string "I'll come by to speak with her later.$"

Present_Gym_Text_GymStatue:
	.string "Porta Bella City Pokémon Gym$"