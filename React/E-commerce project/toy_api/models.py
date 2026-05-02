from django.db import models
from django.contrib.auth.models import AbstractUser
from django.db.models.signals import post_save, pre_save, post_delete, pre_delete
from django.utils.text import slugify
from shortuuid.django_fields import ShortUUIDField
import shortuuid
from phonenumber_field.modelfields import PhoneNumberField

class User(AbstractUser):
    username = models.CharField(unique=True, max_length=150)
    email = models.EmailField(unique=True)
    full_name = models.CharField(max_length=100, null=True, blank=True)

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['username']

    def save(self, *args, **kwargs):
        if self.email:
            email_username = self.email.split("@")[0]
        else:
            email_username = "user"

        if not self.full_name:
            self.full_name = email_username

        if not self.username:
            self.username = email_username

        super().save(*args, **kwargs)

    def __str__(self):
        return self.username


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    image = models.FileField(upload_to="image", default="default/default-user.jpg", null=True, blank=True)
    full_name = models.CharField(max_length=150, null=True, blank=True)
    location = models.CharField(max_length=250, null=True, blank=True)
    country = models.CharField(max_length=60, null=True, blank=True)
    cell = PhoneNumberField(region='BD')

    def __str__(self):
        return self.user.username

    def save(self, *args, **kwargs):
        if not self.full_name:
            self.full_name = self.user.full_name
        super().save(*args, **kwargs)


def create_user_profile(sender, instance, created, **kwargs):
    if created:
        Profile.objects.create(user=instance)


def save_user_profile(sender, instance, **kwargs):
    if hasattr(instance, 'profile'):
        instance.profile.save()


post_save.connect(create_user_profile, sender=User)
post_save.connect(save_user_profile, sender=User)

class Category(models.Model):
    title=models.CharField(max_length=50)
    slug=models.SlugField(null=True, blank=True)

    def __str__(self) -> str:
        return self.title
    def save(self, *args, **kwargs):
        if self.slug=="" or self.slug==None:
            self.slug=slugify(self.title)

        super(Category, self).save(*args, **kwargs)
    def product_count(self):
        return Product.objects.filter(category=self).count()
    
class Product(models.Model):
    user=models.ForeignKey(User,on_delete=models.CASCADE, null=True, blank=True)
    title = models.CharField(max_length=255)
    category = models.ForeignKey(Category, blank=True, null=True, on_delete=models.CASCADE)
    description = models.TextField()
    price = models.DecimalField(max_digits=10, decimal_places=2)
    stock = models.PositiveIntegerField(default=0)
    is_available = models.BooleanField(default=True)
    min_age = models.PositiveIntegerField()
    max_age = models.PositiveIntegerField(null=True, blank=True)    
    # brand = models.CharField(max_length=100, blank=True)
    slug=models.SlugField(unique=True, null=True, blank=True)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        ordering=["-created_at"]
        verbose_name_plural="Products"

    def __str__(self) -> str:
        return self.title
    
    def save(self, *args, **kwargs):
        if self.slug=="" or self.slug==None:
            self.slug=slugify(self.title) + "-" + shortuuid.uuid()[:3]

        super(Product, self).save(*args, **kwargs)

    @property
    def in_stock(self):
        return self.stock > 0

class ProductImage(models.Model):
    product=models.ForeignKey(Product, on_delete=models.CASCADE, related_name='images')
    img=models.ImageField(upload_to='productsImage', null=False)
    uploaded_at = models.DateTimeField(auto_now_add=True)


class Cart(models.Model):  
    profile=models.ForeignKey(Profile,on_delete=models.CASCADE, null=True, blank=True)
    session_id = models.CharField(max_length=255, null=True, blank=True)

    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        if self.profile:
            return f"{self.profile.user.username}'s Cart"
        return f"Cart {self.session_id}"

    @property
    def total_price(self):
        return sum(item.total_price for item in self.items.all())
    
class CartItem(models.Model):
    cart = models.ForeignKey(
        Cart,
        related_name="items",
        on_delete=models.CASCADE
    )
    product = models.ForeignKey(
        Product,
        on_delete=models.CASCADE
    )

    quantity = models.PositiveIntegerField(default=1)
    price = models.DecimalField(max_digits=10, decimal_places=2)
    added_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"{self.product.title} ({self.quantity})"

    @property
    def total_price(self):
        return self.price * self.quantity
    
