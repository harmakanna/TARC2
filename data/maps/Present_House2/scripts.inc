Present_House2_MapScripts::
	.byte 0

Present_House2_EventScript_SentimentalWoman::
	lock
	faceplayer
	call Script_GetNPCFacingDirection
	goto_if_unset FLAG_HIDE_PRESENT_HOUSE2_MISSINGMAN, Present_House2_EventScript_SentimentalWomanHappy
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_House2_EventScript_SentimentalWomanPreGame
	returnqueststate QUEST_SENTIMENTAL
	switch VAR_RESULT
	case 1, Present_House2_EventScript_SentimentalWomanActivate
	case 2, Present_House2_EventScript_SentimentalWomanActive
	case 3, Present_House2_EventScript_SentimentalWomanReward
	case 4, Present_House2_EventScript_SentimentalWomanComplete
	release
	end

Present_House2_EventScript_SentimentalWomanHappy::
	returnqueststate QUEST_SENTIMENTAL
	goto_if_eq VAR_RESULT, 2, Present_House2_EventScript_SentimentalWomanHappyReward
	goto_if_eq VAR_RESULT, 3, Present_House2_EventScript_SentimentalWomanHappyReward
	msgbox Present_House2_Text_SentimentalWomanHappy, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_House2_EventScript_SentimentalWomanHappyReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanHappyDoIKnowYou
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanHappyReward
	closemessage
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_SENTIMENTAL, SUB_QUEST_SAVE_THE_LUVDISCS
	completequest QUEST_SENTIMENTAL
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_House2_EventScript_SentimentalWomanActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanSigh
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_CanIHelpYouWithSomething
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanMaybeYouKnow
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ICanCertainlyTry
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanOhThankYou
	startquest QUEST_SENTIMENTAL
	setflag FLAG_SAVE_THE_LUVDISCS
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_House2_EventScript_SentimentalWomanActive::
	msgbox Present_House2_Text_SentimentalWomanIfOnly, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_House2_EventScript_SentimentalWomanReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IFoundWhatYoureLookingFor
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanYouFoundIt
	removeitem ITEM_HEART_SCALE
	speakername NULL
	playfanfare MUS_OBTAIN_TMHM
	message Present_House2_Text_LookerGaveHeartScale
	waitmessage
	waitfanfare
	speak LOCALID_SENTIMENTAL_WOMAN, VAR_0x8005, Name_Sentimental_Woman, Present_House2_Text_SentimentalWomanThisMeansSoMuch
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_House2_Text_LookerIShouldntTellHerWhere
	completequest QUEST_SENTIMENTAL
	clearflag FLAG_SAVE_THE_LUVDISCS
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_House2_EventScript_SentimentalWomanComplete::
	speakername Name_Sentimental_Woman
	msgbox Present_House2_Text_SentimentalWomanComplete, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_House2_EventScript_SentimentalWomanPreGame::
	msgbox Present_House2_Text_SentimentalWomanIWonderWhen, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Present_House2_EventScript_MissingMan::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_MISSING_MAN, Present_House2_Movement_EmoteHeart
	waitmovement 0
	delay 50
	msgbox Present_House2_Text_MissingMan, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MISSING_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_House2_Text_LookerGaveHeartScale:
	.string "Looker gave Melissa the heart scale!$"
	
Present_House2_Text_SentimentalWomanIWonderWhen:
	.string "Sigh…\p"
	.string "I wonder when my hubby might return…$"

Present_House2_Text_SentimentalWomanSigh:
	.string "Sigh…\p"
	.string "If only I could go back to the\n"
	.string "good old days…$"

Present_House2_Movement_EmoteHeart:
	emote_heart
	step_end

Present_House2_Text_SentimentalWomanYouFoundIt:
	.string "Oh, you found it?\p"
	.string "You found some sort of sign the\n"
	.string "Luvdisc still swarm these bays?\p"
	.string "Show me, please!$"

Present_House2_Text_SentimentalWomanThisMeansSoMuch:
	.string "Thank you so, so much, sir!\p"
	.string "This is a sign to me that things\n"
	.string "really can go back to how they were!\p"
	.string "I hope I can see them along the\n"
	.string "bay soon!$"

Present_House2_Text_LookerIShouldntTellHerWhere:
	.string "All in a day's work.\p"
	.string "(I suppose I shouldn't tell her)\n"
	.string "(where exactly I got this…)$"

Present_House2_Text_SentimentalWomanMaybeYouKnow:
	.string "Oh sir, my husband proposed to me\n"
	.string "at the lighthouse 5 years ago today\l"
	.string "before shipping off to the war.\p"
	.string "Back then, swarms of Luvdisc would\n"
	.string "glide along the water, glimmering\l"
	.string "over the freshwater bay.\p"
	.string "But once Porta Bella became a hot\n"
	.string "destination for cruise lines, the\l"
	.string "increased ship traffic drove them\l"
	.string "all away…\p"
	.string "I'm not sure how, but if it is at\n"
	.string "all possible, could you bring me\l"
	.string "some evidence the Luvdisc still\l"
	.string "congregate here?$"

Present_House2_Text_SentimentalWomanOhThankYou:
	.string "Oh, thank you kindly!\p"
	.string "I would give anything to see those\n"
	.string "glistening scales just one more time…$"

Present_House2_Text_SentimentalWomanIfOnly:
	.string "I would give anything to see those\n"
	.string "glistening scales just one more time…$"

Present_House2_Text_MissingMan:
	.string "Ain't my wife a beauty?\p"
	.string "Her heart scale earrings make her\n"
	.string "look as stunning as she was the\l"
	.string "day I proposed!$"

Present_House2_Text_SentimentalWomanHappy:
	.string "Oh, I love my husband so much!\p"
	.string "The day he shipped off to the war,\n"
	.string "he found me these heart scales\l"
	.string "on the beach and made them into\l"
	.string "earrings!$"

Present_House2_Text_SentimentalWomanComplete:
	.string "Sigh…\p"
	.string "Thank you, sir, but the hole in my\n"
	.string "heart is still empty…\p"
	.string "I wonder when my hubby might return…$"

Present_House2_Text_SentimentalWomanHappyDoIKnowYou:
	.string "Oh, I love my husband so much!\p"
	.string "Wait, do I know you?$"

Present_House2_Text_SentimentalWomanHappyReward:
	.string "Hmm… So you're saying my husband\n"
	.string "never came back and I wanted a\l"
	.string "heart scale from the shore?\p"
	.string "Why?\p"
	.string "Luvdisc are pests, they swarm\n"
	.string "like crazy!\p"
	.string "And my hubby would NEVER leave\n"
	.string "me like that!\p"
	.string "But it doesn't sound like you're\n"
	.string "lying to me…\p"
	.string "Fine, I guess I can reward you…$"