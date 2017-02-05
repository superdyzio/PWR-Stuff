# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('oceny', '0005_konkurencja_kon'),
    ]

    operations = [
        migrations.AlterModelOptions(
            name='druzyna',
            options={'ordering': ('Wynik_S',), 'verbose_name_plural': 'Dru\u017cyny'},
        ),
    ]
