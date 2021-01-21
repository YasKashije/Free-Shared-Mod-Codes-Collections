//Player
OnDamage
if (Menu.toggle1)
		if (this.IsInReviveSave())
		{
			return 0;
		}
		if (this.CurrentHP <= 0)
		{
			return 0;
		}
		damage = damage * (100 + MonoSingleton<BattleManager>.instance.GlobalAttackAddScale100()) / 100;
		this.mGameFramesOfLastBeDamaged = MonoSingleton<LockstepManager>.instance.CurGameFrame;
		if (Menu.toggle1)
		{
			if (this.IsMyself && this.IsMyTeam)
			{
				this.CurrentHP -= damage / 5;
			}
			else
			{
				this.CurrentHP -= damage * 5;
			}
		}
		else
		{
			this.CurrentHP -= damage;
		}
