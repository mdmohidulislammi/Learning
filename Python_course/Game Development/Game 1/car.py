import pygame
import random

# Initialize
pygame.init()

# Screen size
WIDTH, HEIGHT = 400, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("2D Car Game")

# Load images
bg = pygame.image.load("Preview (Variation A).png")

bg = pygame.transform.scale(bg, (WIDTH, HEIGHT))

player_car = pygame.image.load("Sample.png")
player_car = pygame.transform.scale(player_car, (50, 90))

enemy_car = pygame.image.load("Sample.png")
enemy_car = pygame.transform.scale(enemy_car, (50, 90))

# Position
player_x = WIDTH // 2 - 25
player_y = HEIGHT - 110
player_speed = 40

enemy_x = random.randint(50, WIDTH - 100)
enemy_y = -100
enemy_speed = 5

# Score
score = 0
font = pygame.font.SysFont(None, 36)

# Clock
clock = pygame.time.Clock()
FPS = 60

# Game loop
running = True
while running:
    screen.blit(bg, (0, 0))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Controls
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed
    if keys[pygame.K_RIGHT] and player_x < WIDTH - 50:
        player_x += player_speed

    # Move enemy
    enemy_y += enemy_speed
    if enemy_y > HEIGHT:
        enemy_y = -100
        enemy_x = random.randint(50, WIDTH - 100)
        score += 1
        enemy_speed += 0.3

    # Draw cars
    screen.blit(player_car, (player_x, player_y))
    screen.blit(enemy_car, (enemy_x, enemy_y))

    # Collision
    player_rect = pygame.Rect(player_x, player_y, 50, 90)
    enemy_rect = pygame.Rect(enemy_x, enemy_y, 50, 90)
    if player_rect.colliderect(enemy_rect):
        print("Game Over")
        running = False

    # Score display
    score_text = font.render(f"Score: {score}", True, (255, 255, 255))
    screen.blit(score_text, (10, 10))

    pygame.display.update()
    clock.tick(FPS)

pygame.quit()
