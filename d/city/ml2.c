// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"dongmen",
		"north" : __DIR__"ml3",
	]));
	set("no_clean_up", 0);
        set_temp("wayao1",1);
	setup();
	replace_program(ROOM);
}