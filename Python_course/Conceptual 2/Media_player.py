from abc import ABC, abstractmethod


class Description:
    def __init__(self, description):
        self.__description = description

    def get_description(self):
        return self.__description


class Media(ABC):
    def __init__(self, title, duration):
        self.title = title
        self.duration = duration

    @abstractmethod
    def play(self):
        pass


class Music(Media, Description):
    def __init__(self, title, duration, description):
        Description.__init__(
            self, description
        )  # not super.__init__() because we don't know where the properties go
        Media.__init__(self, title, duration)

    def play(self):
        print( f"Music title : {self.title}")

    def info(self):
        print(
            f"Music Title : {self.title}  Duration : {self.duration} Description : {self.get_description()}"
        )


class Video(Media, Description):
    def __init__(self, title, duration, description):
        Description.__init__(
            self, description
        )  # not super.__init__() because we don't know where the properties go
        Media.__init__(self, title, duration)

    def play(self):
         print( f"Video title : {self.title}")

    def info(self):
        print(
            f"Vieoe Title : {self.title}  Duration : {self.duration} Description : {self.get_description()}"
        )


class Audio(Media, Description):
    def __init__(self, title, duration, description):
        Description.__init__(
            self, description
        )  # not super.__init__() because we don't know where the properties go
        Media.__init__(self, title, duration)

    def play(self):
         print( f"Audio title : {self.title}")

    def info(self):
        print(
            f"Audio Title : {self.title}  Duration : {self.duration} Description : {self.get_description()}"
        )


class Library:
    def __init__(self):
        self.__media_items = []
        self.__media_by_genre = {
            "Music" : [], 
            "Video" : [], 
            "Audio" : []
        }
        self.__genre=""

    def get_media_item(self):
        return self.__media_items

    def get_media_by_genre(self):
        return self.__media_by_genre

    def add_media(self, media):
        self.__media_items.append(media)
        if isinstance(media, Music):
            self.__genre='Music'
        elif isinstance(media, Video):
             self.__genre='Video'
        elif isinstance (media, Audio):
            self.__genre='Audio'
        if self.__genre in self.__media_by_genre:
            self.__media_by_genre[self.__genre].append(media)
        else:
            self.__media_by_genre[self.__genre] =[media,]


class User(ABC):
    def __init__(self, name):
        self.name = name

    @abstractmethod
    def play_media(self):
        pass


class FreeUser(User):
    def __init__(self, name):
        super().__init__(name)

    def play_media(self, library):
        for media in library.get_media_item():
            media.play()


class PremiumUser(User):
    def __init__(self, name):
        super().__init__(name)
        self.__favourite=""
    def set_favourite(self, genre):
        self.__favourite=genre
    def get_favourite(self):
        return self.__favourite
    def play_media(self, library):
        if self.__favourite in library.get_media_by_genre():
            for media in library.get_media_by_genre()[self.__favourite]:
                media.play()
        else:
            print("Invalid Input")


library = Library()
music2 = Music("Tujhe kaise bay de ", "3.45", "Song by Inian singer")
music3 = Music("Tune jo na kaha", "4.15", "Pritam song")
music1 = Music("Tere liye hi sanam", "5 min", "Song by funny hujur")
video1 = Video("Tere lin", "3.2", "Indian song")
video2 = Video("tu kaise mujhko batay", "1.5", "Hot song")
video3 = Video("Tujhe bina sanam", "5.12", "Romantic song")
library.add_media(music1)
library.add_media(music2)
library.add_media(music3)
library.add_media(video1)
library.add_media(video2)
library.add_media(video3)
# Music("Tere liye hi sanam", "5 min", "Song by funny hujur").play()
# music1.play()
# music1.info()

# free=FreeUser("Person1")
# free.play_media(library)
Premium=PremiumUser(library)
Premium.set_favourite("Audio")
Premium.play_media(library)

# print(library.get_media_by_genre())