Present_Cafe_MapScripts::
	.byte 0

Present_Cafe_EventScript_Emma::
	lock
	returnqueststate QUEST_BONJOUR_EMMA
	goto_if_eq VAR_RESULT, 4, Present_Cafe_EventScript_EmmaPostQuest
	call Script_GetNPCFacingDirection
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaBonjour
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBonjour
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaComoCaVa
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_1, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_1_1
	goto_if_eq VAR_RESULT, 2, Present_Cafe_EventScript_EmmaLeaveYouAlone
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerBienMerci
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaTresBien
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWhatDoISayHere, MSGBOX_DEFAULT
	multichoice 0, 3, MULTI_SPEAK_WITH_EMMA_2, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_2_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaDontKnowFrench_2_2
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeMappelle
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaEnchantee
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerHuh, MSGBOX_DEFAULT
	multichoice 0, 6, MULTI_SPEAK_WITH_EMMA_3, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaDontKnowFrench_3_1
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaSad
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJePeux
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaMerciBeaucoup
	multichoice 0, 6, MULTI_EMMA_GIVEMON, TRUE
	switch VAR_RESULT
	goto_if_eq VAR_RESULT, 0, Present_Cafe_EventScript_EmmaGiveGumshoos
	goto_if_eq VAR_RESULT, 1, Present_Cafe_EventScript_EmmaGiveMeowstic
	release
	end

Present_Cafe_EventScript_EmmaPostQuest::
	faceplayer
	speakername Name_Emma
	msgbox Present_Cafe_Text_EmmaPostQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_1_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerOui
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaLeaveYouAlone::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMal
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaLeaveYouAlone
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerMonNom
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_2_2::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerJeSuisLooker
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaDontKnowFrench_3_1::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerSure
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaDontSpeakFrench
	goto Present_Cafe_EventScript_EmmaWrongAnswer
	end

Present_Cafe_EventScript_EmmaSad::
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_Cafe_Text_LookerNoThanks
	speak LOCALID_CAFE_EMMA, VAR_0x8005, Name_Emma, Present_Cafe_Text_EmmaAhDaccord
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaWrongAnswer::
	speakername Name_Looker
	msgbox Present_Cafe_Text_LookerWrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_Cafe_EventScript_EmmaFinishQuest::
	completequest QUEST_BONJOUR_EMMA
	release
	end

Present_Cafe_Text_EmmaBonjour:
	.string "Bonjour!$"

Present_Cafe_Text_LookerBonjour:
	.string "Bonjour?$"

Present_Cafe_Text_EmmaComoCaVa:
	.string "Como ça va?$"

Present_Cafe_Text_LookerWhatDoISayHere:
	.string "(What do I say here…?)$"

Present_Cafe_Text_LookerBienMerci:
	.string "Bien, merçi. Ça va?$"

Present_Cafe_Text_LookerOui:
	.string "Oui…?$"

Present_Cafe_Text_LookerMal:
	.string "Pas bien…?$"

Present_Cafe_Text_EmmaLeaveYouAlone:
	.string "Ah…\p"
	.string "Je vous laisserai tranquille.$"

Present_Cafe_Text_EmmaTresBien:
	.string "Bien ça va! Je m'appelle Emma!\n"
	.string "Et vous?$"

Present_Cafe_Text_LookerMonNom:
	.string "Mon nom est Looker…?$"

Present_Cafe_Text_LookerJeSuisLooker:
	.string "Je suis Looker…?$"

Present_Cafe_Text_LookerJeMappelle:
	.string "Je m'appelle…\p"
	.string "Looker.$"

Present_Cafe_Text_EmmaEnchantee:
	.string "Enchantée, Looker!\p"
	.string "Mon Pokémon veulent voir Porta Bella\n"
	.string "et combattrent des combats, mais je\l"
	.string "veux boire du café toute la journée…\p"
	.string "Seriez vous en mesure un Pokémon avec\n"
	.string "vous et combattre avec lui,\l"
	.string "s'il vous plaît?$"

Present_Cafe_Text_LookerHuh:
    .string "(Huh…?)$"

Present_Cafe_Text_LookerSure:
	.string "Sure…?$"

Present_Cafe_Text_EmmaDontSpeakFrench:
	.string "Ah? Vous non parlez pas Français?\n"
	.string "Tant pis…$"

Present_Cafe_Text_LookerNoThanks:
	.string "Je ne veux pas.$"

Present_Cafe_Text_EmmaAhDaccord:
	.string "Ah, d'accord…$"

Present_Cafe_Text_LookerJePeux:
	.string "Bien sûr.$"

Present_Cafe_Text_EmmaMerciBeaucoup:
	.string "Merçi beaucoup!\p"
	.string "Quel Pokémon veux-vous?$"

Present_Cafe_Text_EmmaPostQuest:
	.string "Merçi beaucoup, Looker!$"

Present_Cafe_Text_LookerWrongAnswer:
	.string "(Drat, wrong response…)$"