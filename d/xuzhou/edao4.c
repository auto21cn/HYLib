inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵����������������ǳ���
�֡���ʱ������������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG );

	set("exits", ([
		"north"      : __DIR__"dadao",
		"southeast"      : __DIR__"edao3",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}


