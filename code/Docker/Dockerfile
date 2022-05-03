FROM python:3.8.12-slim

WORKDIR /home/app

# install requirements
RUN apt-get update && apt-get install -y libgl1 && apt-get install -y libglib2.0-0
COPY requirements.txt .
RUN pip install -r requirements.txt

# copy model

#COPY model model

# copy code

COPY main.py .
ENV PYTHONPATH hw1

# standard cmd

ENTRYPOINT [ "python", "main.py" ]

