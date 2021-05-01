monoString *(*String__CreateString)(void *_this, const char *str) = (monoString *(*)(void *, const char *))getRealOffset(0x1908454);

monoString(*orig_TotalTickets)(void *instance);
monoString TotalTickets(void *instance) {
	return String__CreateString(NULL, "999999");
}

void StoryscapeHook(){
	MSHookFunction((void *)getRealOffset(0x4232E0), (void *)TotalTickets, (void **) &orig_TotalTickets);
}