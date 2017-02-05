# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('oceny', '0003_auto_20150603_0421'),
    ]

    operations = [
        migrations.AlterField(
            model_name='uzytkownik',
            name='uprawnienia',
            field=models.CharField(default=b'0000000000000000000000000000000000000000', max_length=40),
        ),
    ]
