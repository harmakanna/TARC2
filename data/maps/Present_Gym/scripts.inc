Present_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Gym_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_Gym_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, Present_Gym_OnResume
	.byte 0

Present_Gym_OnTransition:
	call_if_unset FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_ResetTrainers
	end

Present_Gym_EventScript_ResetTrainers::
	cleartrainerflag TRAINER_LEAH
	cleartrainerflag TRAINER_TASHA
	cleartrainerflag TRAINER_BLAKE
	cleartrainerflag TRAINER_SAMANTHA
	cleartrainerflag TRAINER_CONNIE
	cleartrainerflag TRAINER_SEBASTIAN
	return

Present_Gym_OnFrame:
	map_script_2 VAR_PRESENT_GYM_STATE, 0, Present_Gym_EventScript_GuyPushesYouOut
	map_script_2 VAR_PRESENT_GYM_STATE, 1, Present_Gym_EventScript_GuyIntroducesQuest
	.2byte 0

Present_Gym_EventScript_GuyPushesYouOut::
	lockall
	playse SE_PIN
	applymovement LOCALID_GYM_GUY, Present_Gym_Movement_GymGuyWalksToPlayer
	waitmovement 0
	goto_if_unset FLAG_ENTERED_GYM_IN_INTRO, Present_Gym_EventScript_LookerMeetsGuyPregame
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_TheresAChallenger, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PLAYER
	warp MAP_PRESENT_TOWN, 55, 18
	waitstate
	releaseall
	end

Present_Gym_EventScript_LookerMeetsGuyPregame::
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerHelloPregame
	speak LOCALID_GYM_GUY, DIR_SOUTH, Name_Gym_Guy, Present_Gym_Text_TheresAChallenger
	speak LOCALID_PLAYER, DIR_NORTH, Name_Looker, Present_Gym_Text_LookerUnderstandable
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PLAYER
	setflag FLAG_ENTERED_GYM_IN_INTRO
	warp MAP_PRESENT_TOWN, 55, 18
	waitstate
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

Present_Gym_OnResume:
	special HealPlayerParty
	end

Present_Gym_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_PhoebePostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	goto_if_set FLAG_SPOKE_TO_PHOEBE, Present_Gym_EventScript_PhoebeStartBattleFast
	call Script_GetNPCFacingDirection
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeHiLooker
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerImHereOnOfficialBusiness
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeIHeardYouWanted
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerCorrect
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeThankYou
	setflag FLAG_SPOKE_TO_PHOEBE
	trainerbattle_no_intro TRAINER_PHOEBE, Present_Gym_Text_PhoebeDefeat
	goto Present_Gym_EventScript_PhoebeDefeated
	end

Present_Gym_EventScript_PhoebeStartBattleFast::
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeRematch
	trainerbattle_no_intro TRAINER_PHOEBE, Present_Gym_Text_PhoebeDefeat
	goto Present_Gym_EventScript_PhoebeDefeated
	end

Present_Gym_EventScript_PhoebePostBattleSpeech::
	faceplayer
	speakername Name_Phoebe
	msgbox Present_Gym_Text_PhoebePostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Gym_EventScript_PhoebeDefeated::
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeICouldGoForAnother
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerNoTimeToFoolAround
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeFineWhatDoYouNeed
	call_if_unset FLAG_DEFEATED_MATT, Present_Gym_EventScript_PhoebeTeamAquaSuspicious
	call_if_set FLAG_DEFEATED_MATT, Present_Gym_EventScript_PhoebeIDontKnow
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerHmm
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeAnyTime
	multichoice 0, 6, MULTI_PHOEBE_GIVEMON, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Gym_EventScript_PhoebeGiveDusknoir
	goto_if_eq VAR_RESULT, 1, Present_Gym_EventScript_PhoebeGiveSableye
	end

Present_Gym_EventScript_PhoebeDefeatedSetFlags::
	special HealPlayerParty
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	setflag FLAG_DEFEATED_ELITE_4_PHOEBE
	settrainerflag TRAINER_LEAH
	settrainerflag TRAINER_TASHA
	settrainerflag TRAINER_BLAKE
	settrainerflag TRAINER_SAMANTHA
	settrainerflag TRAINER_CONNIE
	settrainerflag TRAINER_SEBASTIAN
	completequest QUEST_DEFEAT_PHOEBE
	setflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	setflag FLAG_PLAY_LOOKER_GYM_ON_TRANSITION
	release
	end

Present_Gym_EventScript_PhoebeTeamAquaSuspicious::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerINeedInfoOnTwo
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeTeamAquaSuspicious
	return

Present_Gym_EventScript_PhoebeIDontKnow::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Gym_Text_LookerINeedInfoOnOne
	speak LOCALID_GYM_PHOEBE, VAR_0x8005, Name_Phoebe, Present_Gym_Text_PhoebeTheStormsAreCertainlyWeird
	return

Present_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, Present_Gym_EventScript_GymGuyBeatPhoebe
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_GymGuyJustKnowRepeat, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Gym_EventScript_GymGuyBeatPhoebe::
	speakername Name_Gym_Guy
	msgbox Present_Gym_Text_GymGuyBeatPhoebe, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ Expert, TRAINER_LEAH
Present_Gym_EventScript_GymTrainer1::
	trainerbattle_single TRAINER_LEAH, Present_Gym_Text_GymTrainer1Intro, Present_Gym_Text_GymTrainer1Defeat
	msgbox Present_Gym_Text_GymTrainer1PostBattle, MSGBOX_AUTOCLOSE
	end

@ Battle Girl, TRAINER_DAISY
Present_Gym_EventScript_GymTrainer2::
	trainerbattle_double TRAINER_DAISY, Present_Gym_Text_GymTrainer2Intro, Present_Gym_Text_GymTrainer2Defeat, Common_Text_NotEnoughPokemon
	msgbox Present_Gym_Text_GymTrainer2PostBattle, MSGBOX_AUTOCLOSE
	end

@ Ranger M, TRAINER_SEBASTIAN
Present_Gym_EventScript_GymTrainer3::
	trainerbattle_double TRAINER_SEBASTIAN, Present_Gym_Text_GymTrainer3Intro, Present_Gym_Text_GymTrainer3Defeat, Common_Text_NotEnoughPokemon
	msgbox Present_Gym_Text_GymTrainer3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Ranger F, TRAINER_SAMANTHA
Present_Gym_EventScript_GymTrainer4::
	trainerbattle_single TRAINER_SAMANTHA, Present_Gym_Text_GymTrainer4Intro, Present_Gym_Text_GymTrainer4Defeat
	msgbox Present_Gym_Text_GymTrainer4PostBattle, MSGBOX_AUTOCLOSE
	end

@ Beauty, TRAINER_CONNIE
Present_Gym_EventScript_GymTrainer5::
	trainerbattle_double TRAINER_CONNIE, Present_Gym_Text_GymTrainer5Intro, Present_Gym_Text_GymTrainer5Defeat, Common_Text_NotEnoughPokemon
	msgbox Present_Gym_Text_GymTrainer5PostBattle, MSGBOX_AUTOCLOSE
	end


@ Hex Maniac Bottom, TRAINER_TASHA
Present_Gym_EventScript_GymTrainer6::
	trainerbattle_double TRAINER_TASHA, Present_Gym_Text_GymTrainer6Intro, Present_Gym_Text_GymTrainer6Defeat, Common_Text_NotEnoughPokemon
	msgbox Present_Gym_Text_GymTrainer6PostBattle, MSGBOX_AUTOCLOSE
	end

Present_Gym_EventScript_GymStatue::
	msgbox Present_Gym_Text_GymStatue, MSGBOX_SIGN
	end

Present_Gym_Text_PhoebeICouldGoForAnother:
	.string "That.\p"
	.string "Was.\p"
	.string "EXHILERATING!\p"
	.string "C'mon Looker, let's do another! I can\n"
	.string "even heal up your Pokémon right now!$"

Present_Gym_Text_LookerNoTimeToFoolAround:
	.string "I have no time to fool around any\n"
	.string "longer than I already have.\p"
	.string "Could you please help with the\n"
	.string "investigation?$"

Present_Gym_Text_PhoebeFineWhatDoYouNeed:
	.string "Fine… What do you need…?$"

Present_Gym_Text_LookerINeedInfoOnTwo:
	.string "I need information on two things -\n"
	.string "Team Aqua and any recent goings-on\l"
	.string "in Porta Bella you might be privy to.$"

Present_Gym_Text_LookerINeedInfoOnOne:
	.string "I need information on the recent\n"
	.string "lightning storms in Porta Bella.\p"
	.string "I have already cleared Team Aqua of\n"
	.string "all suspicion.$"

Present_Gym_Text_PhoebeTeamAquaSuspicious:
	.string "Well, Team Aqua has been acting\n"
	.string "suspicious ever since they moved in.\p"
	.string "They're constantly doing experiments\n"
	.string "on the local wild Pokémon, which has\l"
	.string "put them at odds with the city and\l"
	.string "the residents of Porta Bella.\p"
	.string "I wouldn't be surprised if they had\n"
	.string "something to do with the storm.\p"
	.string "Outside of that, we've also had a few\n"
	.string "gym challengers come by, as we just\l"
	.string "started gym season a few days ago.\p"
	.string "There's a few trainers who have come\n"
	.string "by already, but only one has been\l"
	.string "strong enough to beat me thus far.\p"
	.string "Does that help?$"

Present_Gym_Text_PhoebeTheStormsAreCertainlyWeird:
	.string "The big storm which rolled in earlier\n"
	.string "is certainly weird…\p"
	.string "If it's not Team Aqua who's the culprit,\n"
	.string "I couldn't imagine who it would be…\p"
	.string "I suppose you could check in with the\n"
	.string "Rangers if you haven't already?\p"
	.string "Outside of that, we've also had a few\n"
	.string "gym challengers come by, as we just\l"
	.string "started gym season a few days ago.\p"
	.string "There's a few trainers who have come\n"
	.string "by already, but only one has been\l"
	.string "strong enough to beat me thus far.\p"
	.string "Does that help?$"

Present_Gym_Text_LookerHmm:
	.string "Hmm…\p"
	.string "Thank you, Phoebe. I believe I am now\n"
	.string "closer to cracking open this case!$"

Present_Gym_Text_PhoebeAnyTime:
	.string "Any time, Looker! Thanks for such an\n"
	.string "exciting battle!\p"
	.string "While you're in town, feel free to\n"
	.string "borrow a Pokémon! It might be a great\l"
	.string "help to your investigation.\p"
	.string "Which would you like?$"

Present_Gym_Text_PhoebeHiLooker:
	.string "Hi!$"

Present_Gym_Text_LookerImHereOnOfficialBusiness:
	.string "Hi, Phoebe. I'm here as part of an\n"
	.string "investigation into Team Aqua and,\l"
	.string "subsequently, the recent downpour.$"

Present_Gym_Text_PhoebeIHeardYouWanted:
	.string "I heard you were in town! I'd be glad\n"
	.string "to help out, but would you PLEASE save\l"
	.string "me from my job and entertain me with\l"
	.string "a battle?\p"
	.string "Sometimes this new job makes me feel\n"
	.string "like I'm a glorified babysitter…\p"
	.string "I'd appreciate a change of pace…$"

Present_Gym_Text_LookerCorrect:
	.string "I would love to humor this little gym\n"
	.string "challenge.$"

Present_Gym_Text_PhoebeThankYou:
	.string "Thank you!\n"
	.string "Okay Looker…\p"
	.string "Get ready for a beatdown from the\n"
	.string "strongest trainer in Porta Bella!$"

Present_Gym_Text_PhoebeRematch:
	.string "Back again for more?\n"
	.string "Okay Looker…\p"
	.string "Get ready for another beatdown from\n"
	.string "the strongest trainer in Porta Bella!$"

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
	.string "Hopefully she complains less after that\n"
	.string "heated battle…$"

Present_Gym_Text_LookerIAmBack:
	.string "Hello, I am back. I hope there\n"
	.string "isn't a gym challenger around this time?\p"
	.string "I am here on official business to discuss\n"
	.string "the most recent torrent with the leader.\p"
	.string "Would she have time now?$"

Present_Gym_Text_GymGuyYouWereHereEarlier:
	.string "Ah, Looker! I remember you came by here\n"
	.string "earlier.\p"
	.string "The gym leader is, in fact, available to\n"
	.string "speak now!$"

Present_Gym_Text_GymGuyIveHeardOfYou:
	.string "Hello, Looker! I'm so glad to meet you -\n"
	.string "I'm a big fan.\p"
	.string "The gym leader isn't being challenged\n"
	.string "now, so you can go talk to her.$"

Present_Gym_Text_LookerWonderfulCanSheComeUp:
	.string "Wonderful. Could she come up to the front,\n"
	.string "in that case?$"

Present_Gym_Text_GymGuyNoCanDoInTown:
	.string "No can do. She heard you were in the city\n"
	.string "and said she wanted to see what you're\l"
	.string "made of if you swung by, so you gotta\l"
	.string "do the whole gym challenge.\p"
	.string "Being a leader, she rarely gets the\n"
	.string "chance to battle adults.\p"
	.string "Only kids really take the gyms seriously.$"

Present_Gym_Text_GymGuyNoCanDo:
	.string "No can do. I told her you swung by\n"
	.string "earlier and she said she wanted to see\l"
	.string "what you're made of, so you gotta do\l"
	.string "the whole gym challenge.\p"
	.string "Being a leader, she rarely gets the\n"
	.string "chance to battle adults.\p"
	.string "Only kids really take the gyms seriously.$"

Present_Gym_Text_LookerSoSheWantsAChangeOfPace:
	.string "So she wants me to provide a bit of a\n"
	.string "distraction from her normal job?\p"
	.string "I have some time to indulge.$"

Present_Gym_Text_GymGuyGreatJustKnow:
	.string "Great! Just so you know, if you beat any\n"
	.string "gym trainers here but leave the gym,\l"
	.string "you will have to re-fight them!\p"
	.string "The gym leader wants to see how tough a\n"
	.string "member of the police like yourself is.$"

Present_Gym_Text_LookerSure:
	.string "Sure. It's been too long since I did a\n"
	.string "gym challenge. This will be fun.$"

Present_Gym_Text_GymGuyJustKnowRepeat:
	.string "Just so you know, if you leave the gym,\n"
	.string "you will have to refight the trainers!\p"
	.string "Good luck out there!$"

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
	.string "I am here to ask the gym leader about\n"
	.string "the recent activities of Team Aqua?\p"
	.string "I am on official business and would\n"
	.string "appreciate an audience with her.$"

Present_Gym_Text_TheresAChallenger:
	.string "Hello, Looker! Sorry, but a trainer\n"
	.string "is currently challenging the gym.\p"
	.string "You will have to come back later once\n"
	.string "the gym is cleared.$"

Present_Gym_Text_LookerUnderstandable:
	.string "Oh, that's unfortunate.$"

Present_Gym_Text_GymTrainer1Intro:
	.string "Hehehehe…\n"
	.string "I put a spell on you!$"

Present_Gym_Text_GymTrainer1Defeat:
	.string "No! Witchcraft fails me again!$"

Present_Gym_Text_GymTrainer1PostBattle:
	.string "Sometimes I wonder if witchcraft\n"
	.string "is actually real or not…$"

Present_Gym_Text_GymTrainer2Intro:
	.string "Catch this! Kamehameha!$"

Present_Gym_Text_GymTrainer2Defeat:
	.string "Drat, it didn't work!$"

Present_Gym_Text_GymTrainer2PostBattle:
	.string "I've been watching too many TV shows\n"
	.string "lately…$"

Present_Gym_Text_GymTrainer3Intro:
	.string "Man… Why do I gotta be here…\p"
	.string "I want to hang out with wild Pokémon…$"

Present_Gym_Text_GymTrainer3Defeat:
	.string "Sigh…$"

Present_Gym_Text_GymTrainer3PostBattle:
	.string "I don't get paid enough to work as a\n"
	.string "Ranger, so I had to take up a side\l"
	.string "hustle at the gym to make ends meet…$"

Present_Gym_Text_GymTrainer4Intro:
	.string "Porta Bella City is considered the gold\n"
	.string "standard for gym challenges!\p"
	.string "Our gym leader is one of the elites in\n"
	.string "this country!$"

Present_Gym_Text_GymTrainer4Defeat:
	.string "Well, at least I did my part!$"

Present_Gym_Text_GymTrainer4PostBattle:
	.string "Have you figured out who the gym leader\n"
	.string "of Porta Bella is yet?$"

Present_Gym_Text_GymTrainer5Intro:
	.string "This gym is a perfect way for me to get\n"
	.string "out of the sun!\p"
	.string "I could do without all the children\n"
	.string "coming in, though…$"

Present_Gym_Text_GymTrainer5Defeat:
	.string "Oh well…$"

Present_Gym_Text_GymTrainer5PostBattle:
	.string "Living a childfree life is so hard…\n"
	.string "Couldn't they just… like…\p"
	.string "Go away?$"

Present_Gym_Text_GymTrainer6Intro:
	.string "Fufufufu…\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "Why are you looking at me like that?\n"
	.string "I'm just laughing…$"

Present_Gym_Text_GymTrainer6Defeat:
	.string "I swear! I just have a weird laugh!$"

Present_Gym_Text_GymTrainer6PostBattle:
	.string "I've been friends with the gym leader\n"
	.string "since we were kids…\p"
	.string "You won't have an easy time with her…\n"
	.string "Fufufufu…$"

Present_Gym_Text_GymStatue:
	.string "Porta Bella City Pokémon Gym$"