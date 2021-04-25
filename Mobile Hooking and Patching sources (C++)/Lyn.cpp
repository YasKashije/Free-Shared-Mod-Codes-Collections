void* isPlayer_Ptr = (void *)getRealOffset(0x101FA72DC);
MSHookFunction(isPlayer_Ptr, (void*)&hook_isPlayer, (void**)&orig_isPlayer);
//RYNBattleObject.IsMyHero

void* WeakEnemies_Ptr = (void *)getRealOffset(0x101FA6DA8);
MSHookFunction(WeakEnemies_Ptr, (void*)&hook_WeakEnemies, (void**)&orig_WeakEnemies);
//RYNBattleObject.get_MaxHP

void* GodMode_Ptr = (void *)getRealOffset(0x101FA6D40);
MSHookFunction(GodMode_Ptr, (void*)&hook_GodMode, (void**)&orig_GodMode);
//RYNBattleObject.get_HP
	
//UnitTable
Attack
defence
eType

void (*ApplyDamage)(int damageResultType, bool isCritical, int damage, int currentHP, void* actor, bool isNormalAttack, void* skillHitTable, void* skillResultTable, void* valid);
void _ApplyDamage(int damageResultType, bool isCritical, int damage, int currentHP, void* actor, bool isNormalAttack, void* skillHitTable, void* skillResultTable, void* valid){
    bool ismyhero = IsMyHero(actor);
	//os_log(OS_LOG_DEFAULT, "platinmods orig dmg %d", damage);
	if(ismyhero && [switches isSwitchOn: @"Damage multiplier"])
	{ 
		int dmg = [[switches getValueFromSwitch: @"Damage multiplier"] intValue];
		//os_log(OS_LOG_DEFAULT, "platinmods dmg mul %d", dmg);
		damage *= dmg;
	}
	if(!ismyhero && [switches isSwitchOn: @"Defense multiplier"])
	{ 
		int def = [[switches getValueFromSwitch: @"Defense multiplier"] intValue];
		//os_log(OS_LOG_DEFAULT, "platinmods def mul %d", def);
		damage /= def;
	}
    ApplyDamage(damageResultType, isCritical, damage, currentHP, actor, isNormalAttack, skillHitTable, skillResultTable, valid);
}

MSHookFunction((void*)getRealOffset(0x10253A9B4), (void*)_ApplyDamage, (void**)&ApplyDamage);
MSHookFunction((void*)getRealOffset(0x101D5ABAC), (void*)_AddVerifyDamageList, (void**)&AddVerifyDamageList);