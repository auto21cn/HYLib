// Room: /d/gaochang/shulin3.c

inherit ROOM;




void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ���,��ǰ����������������
�Թ�֮�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�
����ϸ���������ף����׺�ǰ������·�϶��е������㼣��
���ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin2",
		"south" : __DIR__"shulin4",
		"west" : __DIR__"shulin"+(random(10)+2),
		"north" : __DIR__"shulin"+(random(10)+2),
	]));

	set("outdoors", "gaochang");
	setup();
	replace_program(ROOM);
}


